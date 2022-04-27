{-EXERCÍCIO 1
Função que verifica se três números podem ser medidas dos lados de um
triângulo.

Note que isso vale se, e somente se, o maior deles é menor do que a soma dos
outros tres.

Se A, B, C são os números dados, com A o maior deles, então a função retorna TRUE se, e somente se,
A<B+C,
ou seja,
2A<A+B+C.

Isso é fácil de programar.-}

maximodedois :: (Ord a) => a -> a -> a
maximodedois a b = if (a>b) then (a) else (b)

maximodetres :: (Ord a) => a -> a -> a -> a
maximodetres a b c = maximodedois (maximodedois a b) c

ehTriangulo :: (Num a,Ord a) => a -> a -> a -> Bool
ehTriangulo x y z = if (m+m<x+y+z) then (True) else (False)
  where m = maximodetres x y z

{-EXERCÍCIO 2
Função que toma três valores válidos para medidas dos lados de um triângulo e
retorna o tipo de triângulo
-}

tipoTriangulo :: (Ord a, Num a) => a -> a -> a -> [Char]
tipoTriangulo x y z
  | not (ehTriangulo x y z) = "Nao e triangulo, :p"
  | (x==y && x==z) = "equilatero"
  | (x==y || x==z || y==z) = "isosceles"
  | otherwise = "escaleno"

{-EXERCÍCIO 3
  É exatamente o que foi feito no exercício anterior. Mas como a questão pede
  explicitamente para utilizar os exercícios anteriores, vamos lá
-}

triangulo :: (Ord a, Num a) => a -> a -> a -> [Char]
triangulo x y z
  | (ehTriangulo x y z) = tipoTriangulo x y z
  | otherwise = "nao eh um triangulo"

{-EXERCÍCIO 4
  Função que toma um inteiro n e retorna a soma dos números pares entre 0 e n.
-}

ehpar :: Int -> Bool
ehpar 0 = True
ehpar 1 = False
{-parece que tem que separar em caso positivo e negativo para verificar paridade

:(

-}
ehpar n
  | n>0 = ehpar (rem (n) 2)
  | otherwise = (ehpar (-n))

somaPares :: Int -> Int
somaPares 0 = 0
somaPares n
  | (n<0) = (-(somaPares (-n)))
  | (ehpar n) = (n + somaPares (n-2))
  | otherwise = (somaPares (n-1))

{-Exercício 5
  Função que recebe inteiros m e n e retorna a série
  2^0m+2^1m+2^2m+...+2^nm-}
{-
O jeito trivial é notar que
2^0m+2^1m+...+2^nm = m(2^(n+1)-1)

Mas vamos fazer do jeito recursivo que é mais legal

Note que 2^0m+...+2^(n+1)m = 2*(2^0m+...+2^nm) + 2^0m
o que simplifica a recursão ;)
-}

somaPot2m :: Int -> Int -> Int
somaPot2m m 0 = m
somaPot2m _ n | (n<0) = error "A segunda entrada tem que ser positiva"
somaPot2m m n = m+ (2*(somaPot2m m (n-1)))

{-Exercício 6
  Função que verifica se um número é primo
-}

--Verifica se algum numero entre 2 e m divide n
divisao :: Int -> Int -> Bool
divisao m n  |(m<2) = error "A primeira entrada tem que ser maior ou igual a 2"
divisao 2 n
  |((rem n 2) == 0) = True
  |otherwise = False
divisao m n
  |(rem m n)==0 = True
  |otherwise = (rem (m-1) n)

primo :: Int -> Bool
primo 0 = False
primo 1 = True
primo 2 = True
primo n | (n<0) = primo (-n)
primo n = not (divisao n-1 n)
