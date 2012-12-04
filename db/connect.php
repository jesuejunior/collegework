<?php

$dbname="sixgames";
$usuario="root";
$password="usbw";

$conn = mysql_connect("localhost:3307", $usuario, $password);
$db = mysql_select_db($dbname, $conn);
mysql_set_charset('utf8');

if(!($conn) OR !($db)){
   echo "Não foi possível estabelecer uma conexão com o gerenciador MySQL. Favor Contactar o Administrador.";
   exit;
}

?>