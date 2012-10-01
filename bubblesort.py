#!/usr/bin/env python2
#_*_ coding: utf-8 _*_

lista = [4, 5, 9, 32, 456, 22, 44, 98, 6, 1, 2]
fim = len(lista)
while fim > 1:
    trocou = False
    x = 0
    while x < (fim - 1):
        if lista[x] > lista[x + 1]:
            trocou = True
            temp = lista[x]
            lista[x] = lista[x + 1]
            lista[x + 1] = temp
        x += 1
    if not trocou:
        break
    fim -= 1
for e in lista:
    print(e)
