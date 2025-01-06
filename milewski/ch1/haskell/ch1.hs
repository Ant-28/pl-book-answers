
data A = Foo | Bar
data B = Baz | Blah
data C = Qux | What
-- f is a function from A to B
-- g is a function from B to C
f :: A -> B
f = undefined
g :: B -> C
g = undefined
h = g . f

