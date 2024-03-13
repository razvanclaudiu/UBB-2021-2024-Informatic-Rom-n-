
/*add_tail([],X,[X]).
add_tail([H|T],X,[H|L]):-
    add_tail(T,X,L).

is_empty(List):-
	not(member(_,List)).*/

%colinear([[1,1],[2,2],[3,3]],X).
/*colinear([],[]).
colinear([P|R],Z):-
	add_tail(_X,P,X1),
	colinear1(X1,R,Z),
	colinear(R,Z).

colinear1(_,[],[]).
colinear1(X,[P|R],Z):-
	add_tail(X,P,X1),
	colinear2(X1,X1,R,Z),
	colinear1(X,R,Z).

colinear(L,Z):-
	colinear(_,_,L,Z).

colinear2(_,_,[],[]).
colinear2(X,[P1,P2|_],[PN|_R],XN):-
	is_list(P1),
	is_list(P2),
	slope(P1,P2,S),
	slope(P1,PN,S),
	add_tail(X,PN,XN).
colinear(X,X,[P|R],Z):-
	not(append([],P,[])),
	add_tail(X,P,X1),
	colinear(X1,X1,R,Z).
colinear(X,X,[P|R],Z):-
	not(append([],P,[])),
	colinear(X,X,R,Z).

sublist(L,SL):-
	append(_,TS,L),
	append(SL,_,TS).*/

slope([X|_],[X|_], S):-
    S is 99999,
    !.
slope( [X1|Y1], [X2,Y2], S ) :-
    X2-X1 =\= 0,
    S is ((Y2-Y1)/(X2-X1)).


comb(L,O) :-
    splitSet(L,_,O).

splitSet([ ],[ ],[ ]).
splitSet([H|T],[H|L],R) :-
    splitSet(T,L,R).
splitSet([H|T],L,[H|R]) :-
    splitSet(T,L,R).

%colinearsl([[1,1],[2,2],[3,3],[1,2],[1,3]],X).

%colinearsl(L: Lista, LF: Lista)
%Lista = Lista
%Model de flux: (i,i), (i,o)
%L - lista initiala
%LF - lista de puncte coliniare
colinearsl(L,SL):-
	findall(SL,comb(L,SL),Slist),
	colinear(Slist,SL).

%colinear(L: Lista, LF: Lista)
%Lista = Lista
%Model de flux (i,i), (i,o)
%L - lista initiala
%LF - lista de puncte coliniare
colinear([],[]).
colinear([H|R],[H|R1]):-
	length(H,N),
	N > 2,
	colinearcheck(H),
        colinear(R,R1),
	!.
colinear([_|R],R1):-
	colinear(R,R1).

%colinearcheck(L)
%Lista = Lista
%Model de flux: (i)
%L - lista de puncte
colinearcheck([P1,P2|H]):-
	slope(P1,P2,S),
	colinearcheck([P2|H],S).

colinearcheck([],_).
colinearcheck([P1,P2|H],S):-
	slope(P1,P2,S),
	colinearcheck([P2|H],S).
colinearcheck(L,_):-
	length(L,N),
	N == 1.





