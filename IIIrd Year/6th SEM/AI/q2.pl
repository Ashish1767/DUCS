max(X,Y,Z):-
(X>Y ->
Z is X;
X<Y->
Z is Y;
X=Y->
write('both are equal'),
write('max is',Z)
).
