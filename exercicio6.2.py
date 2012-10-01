#!/usr/bin/env python2
#_*_ coding: utf-8 _*_

# Faça um programa que leia duas listas e que gere uma terceira com os elementos
# das duas primeiras

lista1 = [1, 2, 3, 4, 5]
lista2 = [6, 7, 8, 9, 0]
lista3 = []

lista3.extend(lista1 + lista2)

print(lista3)
