#!/usr/bin/env python2
# -*- coding:utf-8 -*-

x = "Aquelas sao {0} tipos de pessoas." .format(10)
binary = "binary"
do_not = "don't"
y = "Aqueles que sabem {b} e aqueles que {d}" .format(b=binary, d=do_not)

print x
print y

print "Eu digo: %r" % x
print "Eu tambem digo: '%s'." % y

hilario = False
avaliacao_joker = "Joker não é engraçado?! %r"

print avaliacao_joker % hilario

w = "Isto é o lado esquerdo de..."
e = " uma string com o lado direito."

print w + e
