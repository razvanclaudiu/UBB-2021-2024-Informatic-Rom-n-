%combine([1,5,2,3],[1,2,2,4],L).

%combine(L1:Lista, L2: Lista, Z: Lista)
%Lista = Element*
%Model de flux: (i,i,o),(i,i,i)
%L1 - lista 1
%L2 - lista 2
%Z - reuniunea a celor doua liste
combine(S,[],S).
combine(L1,[H|T],Z):-
	count(L1,H,N),
	N>0,
        combine(L1,T,Z).
combine(L1,[H|T],Z):-
	count(L1,H,N),
	N=0,
	append(L1,[H],Temp),
	combine(Temp,T,Z).

%count(L:Lista,E:Element,N:Element)
%Lista = Element*
%Model de flux: (i,i,o),(i,i,i)
%L - lista
%E - elementul de cautat
%N - numarul de aparitii
count([],_,0).
count([H|T],E,N):-
	H=E,
	count(T,E,Z),
	N is 1+Z.
count([H|T],E,N):-
	E\=H,
	count(T,E,N).

%pairs([1,2,3,4],L).

%pairs(L:Lista,LF:Lista)
%Lista = Element*
%Model de flux: (i,o),(i,i)
%L: Lista de elemente
%LF: Lita de perechi

pairs( [X|T], LF):-
	pairs( X, T, T, LF, []).

pairs( _, [], [], Z, Z).
pairs( _, [], [X|T], LF, Z):-
	pairs( X, T, T, LF, Z).
pairs( X, [Y|T], R, [[X,Y]|LF], Z):-
	pairs( X, T, R, LF, Z).
