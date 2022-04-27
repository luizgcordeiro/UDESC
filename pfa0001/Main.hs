sublist n m x = take (m-n+1) (drop n x)
{-function that takes a list x and two natural
numbers n,m with m>=n, and returns the sublist
of x from index n to m (inclusive). Equivalent
to drop n (take m+1 x). Efficiency when
compared to this form depends on whether
n is greater or smaller than length(x)-m+1,
since this determines how many elements of x
are dropped in the first step.-}

length' :: (Num b) => [a] -> b
length' [] = 0
length' (_:xs) = 1+ (length' xs)

collatz :: (Integral a) => a -> a
collatz x = if (even x) then (div x 2) else (3*x+1)

collatzinf 1 = [1]
collatzinf x = [x] ++ collatzinf (collatz x)

mdc :: Integral a => a->a->a
mdc a b =
  if rem a b == 0 then
    b
  else
    mdc b (rem a b)

{- Função "primeiros n lista" retorna os n primeiros inteiros de uma lista-}

primeiros :: Int -> [a] -> [a]
primeiros 0 xs = []
primeiros n [] = []
primeiros n (x:xs) = x : (primeiros (n-1) xs )






concatenate :: [a] -> [a] -> [a]
concatenate [] x = x
concatenate (x:xs) y = x:(concatenate xs y)
