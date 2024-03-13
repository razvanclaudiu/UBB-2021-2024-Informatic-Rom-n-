%powerof2(E: Element)
%Model de flux: (i)
%E - elementul care va fi verificat daca este o putere a lui 2
powerof2(E):-
	E > 1,
	0 is E /\ (E-1).

%insert(5,[1,2,1,2,4,7,8,9,3],X).

%insert(X: Element, L: Lista eterogena, Z: Lista eterogena)
%Lista = Element*,Lista*
%X: elementul de inserat
%L: lista eterogena
insert(X,L,Z):-
	insert(X,2,L,Z).

insert(_,_, [],[]).
insert(X, N, [Y | Rest], [Y|[X | Rest1]]) :-
	powerof2(N),
	N1 is N+1,
	insert(X, N1, Rest, Rest1).
insert(X, N, [Y | Rest], [Y | Rest1]) :-
	N1 is N+1,
	insert(X, N1, Rest, Rest1).


%multipleinsert([1, [2, 3], 7, [4, 1, 4], 3, 6, [7, 5, 1, 3, 9, 8, 2, 7], 5],X).
multipleinsert(L,Z):-
	multipleinsert(_,L,Z).

multipleinsert(_,[],[]).
multipleinsert(X,[H,G|R],[H,X|R1]):-
	is_list(G),
	insert(H,G,G1),
	append([],G1,X),
	multipleinsert(_K,R,R1).
multipleinsert(X,[H|R],[H|R1]):-
	multipleinsert(X,R,R1).




