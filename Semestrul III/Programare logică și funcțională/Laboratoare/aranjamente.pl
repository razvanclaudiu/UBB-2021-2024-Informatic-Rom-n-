% 6. Generate the list of all arrangements of K elements of a given list.
% Eg: [2, 3, 4] K=2 => [[2,3], [3,2], [2,4], [4,2], [3,4], [4,3]] (not necessary in this order)

% inserare(l1...ln, e) =
%	[e], n = 0
%	e + l1...ln, n >= 1
%	l1 + inserare(l2...ln, e), otherwise

% inserare(L:list, E:number, R:list)
% inserare(i, i, o)

perm([], []).
perm([E|T], P) :-
	perm(T, L),
	insereaza(E, L, P).

insereaza(E, L, [E|L]).
insereaza(E, [H|T], [H|Rez]) :-
	insereaza(E, T, Rez).

% combinari(l1...ln, k) =
%	[], k = 0
%	l1 + combinari(l2...ln, k - 1), k > 0
%	combinari(l2...ln, k), k > 0

% combinari(L:list, K:number, R:list)
% combinari(i, o)

combinari(_, 0, []).
combinari([H|T], K, [H|R]) :-
    K > 0,
    NK is K - 1,
    combinari(T, NK, R).
combinari([_|T], K, R) :-
    K > 0,
    combinari(T, K, R).

% aranjamente(L:list, K:number, R:list)
% aranjamente(i, i, o)

aranjamente(L, K, R) :-
    combinari(L, K, RC),
    perm(RC, R).

% allsolutions(L:list, N:number, R:list)
% allsolutions(i, i, o)

allsolutions(L, N, R, K) :-
    findall(RPartial, aranjamente(L, N, RPartial), R1),
    sumk(R1,R,K).

sum_of_elements_is_k(List, K) :-
	sum_of_elements(List, 0, Sum), Sum =:= K.

sum_of_elements([], Sum, Sum).
sum_of_elements([Head|Tail], Acc, Sum) :-
	NewAcc is Acc + Head,
	sum_of_elements(Tail, NewAcc, Sum).

sumk([],[],_).
sumk([H|T],R,K):-
	sum_of_elements_is_k(H,K),
	!,
	R = [H|NT],
	sumk(T,NT,K).
sumk([_|T],R,K):-
	sumk(T,R,K).

subm([],[]).
subm([_|T],R) :- subm(T,R).
subm([H|T],[H|R]) :- subm(T,R).

subm_all(L,R) :- findall(X,subm(L,X) , R).

combinn([H|_],1,[H]).
combinn([_|T],K,R) :-
combinn(T,K,R).
combinn([H|T],K,[H|R]) :-
K > 1 ,
K2 is K - 1 ,
combinn(T,K2,R).


