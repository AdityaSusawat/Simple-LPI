# Simple-LPI
# Work in progress

Writing a simple lexer, parser, and interpreter for a LISP-like language.

(* 2 2) will be the same as (2*2)

(+ (* 2 2) 3) will be the same as ((2*2) + 3)

(define x 5) to define a variable

(lambda (x) (* x x)) a function that that takes x and returns x*x

-, /, ==, !=, <, <=, >, >= operators and an if function is also supported.
