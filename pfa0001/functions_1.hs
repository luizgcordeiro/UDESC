{- Função isin x y que verifica se x pertence à lista y -}
isin :: Eq a => a -> [a] -> Bool
isin _ [] = False
isin y (x:xs) | x == y = True
isin x (_:ys) = isin x ys

{-Função que conta número de elementos -}
numberofelements :: Eq a => [a] -> Int
numberofelements [] = 0
numberofelements (x:xs)
  | isin x xs = numberinxs
  | otherwise = numberinxs + 1
  where numberinxs = numberofelements xs
