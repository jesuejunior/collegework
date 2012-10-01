#!/usr/bin/env python2
# _*_ coding: utf-8 _*_

estoque = {"tomate": [100, 2.30], "alface": [50, 0.49],
        "batata": [1000, 1.20], "feijao": [2000, 1.50]}
venda = []
tmp = []

while True:
    operador = input("Para comprar digite C, para finalizar a compra digite F: ")
    if operador == "C":
        while True:
            produto = input("Digite o produto: ")
            if produto not in estoque:
                print("Infelizmente não temos este produto em estoque. Por favor digite outro.")
            else:
                break
        qtde_venda = int(input("Digite a quantidade: "))
        tmp.append(produto)
        tmp.append(qtde_venda)
        venda.append(tmp)
    elif operador == "F":
        break

total = 0
print("Vendas: \n")
for operacao in venda:
    produto, qtde = operacao
    preco = estoque[produto][1]
    custo = preco * qtde
    print("%12s: %3d x %6.2f = %6.2f" %
            (produto, qtde, preco, custo))
    estoque[produto][0] -= qtde
    total += custo
print("Custo total: %21.2f\n" % total)
print("Estoque:\n")
for chave, dados in estoque.items():
    print("Descrição: ", chave)
    print("Quantidade: ", dados[0])
    print("Preço: %6.2f" % dados[1])
