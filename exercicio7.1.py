#!/usr/bin/env python2
# _*_ coding: utf-8 _*_

string1 = "AABBEFAATT"
busca = "BEA"

if busca in string1:
    print("%s encontrado na posição %d de %s" % (busca, string1.find(busca), string1))
else:
    print("[%s] não foi encontrado!" % busca)
