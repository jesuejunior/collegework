#!/bin/bash

OPEN_PORTS="22 80 443 8001"

IPTABLES=/usr/sbin/iptables

# External link Iface
NET_IFACE=eth0
NET_IP=`ifconfig | grep -A 1 ${NET_IFACE} | grep inet | awk '{print $2}' | awk -F: '{print $2}'`

# Loopback Iface
LO_IP=127.0.0.0/8
LO_IFACE=lo

_stop(){
  echo -n "Flushing Rules..."
  $IPTABLES -F
  $IPTABLES -t nat -F
  $IPTABLES -t mangle -F
  _accept
}

_accept(){
      $IPTABLES -P INPUT ACCEPT
      $IPTABLES -P OUTPUT ACCEPT
      $IPTABLES -P FORWARD ACCEPT

}


_offline() {
    echo -n "Starting OFFLINE firewall..."
    _accept
    echo "ok!"
    exit 0
}

_drop(){
  #echo -n "Dropping ALL packets..."
  $IPTABLES -P INPUT DROP
  $IPTABLES -P OUTPUT ACCEPT
  $IPTABLES -P FORWARD DROP
}

_start(){  

   if [ -z ${NET_IP} ];then
     _offline
   fi
  
  echo -n "Configuring Firewall..."
  _stop
  _drop

  ###########################
  # INPUT                   #
  ###########################

  for PORT in ${OPEN_PORTS} ; do 
    ${IPTABLES} -A INPUT -i ${NET_IFACE} -p tcp --dport ${PORT} -j ACCEPT
  done

  #Libera o LOOPBACK
  ${IPTABLES} -A INPUT -i ${LO_IFACE} -s ${LO_IP} -j ACCEPT 

  #IP Spoofing
  ${IPTABLES} -A INPUT -i ${NET_IFACE} -s ${LO_IP} -j LOG --log-prefix "IP SPoofing: "
  ${IPTABLES} -A INPUT -i ${NET_IFACE} -s ${LO_IP} -j DROP
  ${IPTABLES} -A INPUT -i ${NET_IFACE} -s ${LO_IP} -d ${LO_IP} -j LOG --log-prefix "IP Spoofing: "
  ${IPTABLES} -A INPUT -i ${NET_IFACE} -s ${LO_IP} -d ${LO_IP} -j DROP

  #Hardcore
  ${IPTABLES} -A INPUT -i ${NET_IFACE} -m state –state ESTABLISHED,RELATED -j ACCEPT
  ${IPTABLES} -N LOGDROP
  ${IPTABLES} -A port-scan -p tcp --tcp-flags SYN,ACK,FIN,RST RST -m limit --limit 1/s -j RETURN
  ${IPTABLES} -A port-scan -j DROP

  #Load Balance
  ${IPTABLES} -A PREROUTING -i ${NET_IFACE} -p tcp --dport 8001 -m state --state NEW -m nth --counter 0 --every 4 --packet 0 -j DNAT --to-destination 172.31.13.34:8001
  ${IPTABLES} -A PREROUTING -i ${NET_IFACE} -p tcp --dport 8001 -m state --state NEW -m nth --counter 0 --every 4 --packet 1 -j DNAT --to-destination 172.31.13.34:8001
  ${IPTABLES} -A PREROUTING -i ${NET_IFACE} -p tcp --dport 8001 -m state --state NEW -m nth --counter 0 --every 4 --packet 2 -j DNAT --to-destination 172.31.13.34:8001
  ${IPTABLES} -A PREROUTING -i ${NET_IFACE} -p tcp --dport 8001 -m state --state NEW -m nth --counter 0 --every 4 --packet 3 -j DNAT --to-destination 172.31.13.34:8001
  

  #Pacotes SYN FIN ao mesmo tempo
  $IPTABLES -A INPUT -i $NET_IFACE -p tcp --tcp-flags SYN,FIN SYN,FIN -j LOG --log-prefix "SYN+FIN: "
  $IPTABLES -A INPUT -i $NET_IFACE -p tcp --tcp-flags SYN,FIN SYN,FIN -j DROP

  #Alguem tentando fazer IP Spoofing com meu IP!!
  ${IPTABLES} -A INPUT -p tcp -i ${NET_IFACE} --tcp-flags SYN,ACK SYN,ACK -m state --state NEW -j LOG --log-prefix "IP Spoofing com meu IP: "
  ${IPTABLES} -A INPUT -p tcp -i ${NET_IFACE} --tcp-flags SYN,ACK SYN,ACK -m state --state NEW -j DROP

  #Aceita conexaoes entrantes q ja' foram iniciadas por alguma outra.
  ${IPTABLES} -A INPUT -i ${NET_IFACE} -m state --state ESTABLISHED,RELATED -j ACCEPT

}

_ok(){
  echo "ok"
}

case "$1" in
  'start')
    _start
    _ok
  ;;
  'stop')
    _stop
    _ok
  ;;
  'restart')
    _stop
    _ok
    _start
    _ok
  ;;
  'drop')
    _stop
    _drop
    _ok
  ;;
  *)
  echo "Usage: $0 start|stop|restart|drop"
  exit 1
esac


