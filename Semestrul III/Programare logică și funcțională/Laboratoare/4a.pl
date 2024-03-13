%replace all instances of a number in a list with a given list
replaceall([],_,_,[]).
replaceall([H|T],H,L,[L|T2]) :- 
    replaceall(T,H,L,T2).
replaceall([H|T],X,L,[H|T2]) :-
    H \= X,
    replaceall(T,X,L,T2).