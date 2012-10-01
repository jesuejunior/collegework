#!/usr/bin/env python2
#_*_ coding: utf-8 _*_
# Faça um programa que percorra duas listas e gere uma terceira sem elementos
# repetidos

lista1 = [1, 2, 3, 4, 5]
lista2 = [1, 3, 5, 6, 8]
lista3 = []

lista3 = lista1
for i in lista2:
    if lista2.count(i) != lista1.count(i):
        lista3.append(i)

print(lista3)
