%Facts
male(jack).
male(oliver).
male(ali).
male(james).
male(simon).
male(harry).

female(helen).
female(sophie).
female(jess).
female(lily).

parent_of(jack,jess).
parent_of(jack,lily).
parent_of(helen, jess).
parent_of(helen, lily).
parent_of(oliver,james).
parent_of(sophie, james).
parent_of(jess, simon).
parent_of(ali, simon).
parent_of(lily, harry).
parent_of(james, harry).

/* Rules */
father_of(X,Y):- male(X),
    parent_of(X,Y).

mother_of(X,Y):- female(X),
    parent_of(X,Y).

grandfather_of(X,Y):- male(X),
    parent_of(X,Z),
    parent_of(Z,Y).

grandmother_of(X,Y):- female(X),
    parent_of(X,Z),
    parent_of(Z,Y).

sister_of(X,Y):- %(X,Y or Y,X)%
    female(X),
    father_of(F, Y), father_of(F,X),X \= Y.

sister_of(X,Y):- female(X),
    mother_of(M, Y), mother_of(M,X),X \= Y.

aunt_of(X,Y):- female(X),
    parent_of(Z,Y), sister_of(Z,X),!.

brother_of(X,Y):- %(X,Y or Y,X)%
    male(X),
    father_of(F, Y), father_of(F,X),X \= Y.

brother_of(X,Y):- male(X),
    mother_of(M, Y), mother_of(M,X),X \= Y.

uncle_of(X,Y):-
    parent_of(Z,Y), brother_of(Z,X).

ancestor_of(X,Y):- parent_of(X,Y).

ancestor_of(X,Y):- parent_of(X,Z),
    ancestor_of(Z,Y).


% % Facts
% male(john).
% male(bob).
% female(lisa).
% female(anna).

% parent(john, lisa).
% parent(john, bob).
% parent(anna, lisa).
% parent(anna, bob).

% % Rules
% father(X, Y) :- male(X), parent(X, Y).
% mother(X, Y) :- female(X), parent(X, Y).
% sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.


% % Facts
% male(ram).
% male(raj).
% female(sita).
% female(gita).

% parent(ram, sita).
% parent(ram, raj).
% parent(gita, sita).
% parent(gita, raj).

% % Rules
% father(X, Y) :- male(X), parent(X, Y).
% mother(X, Y) :- female(X), parent(X, Y).
% sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% % % Queries
% % % Query for fathers
% % ?- father(X, sita).
% % % Output: X = ram

% % ?- father(X, raj).
% % % Output: X = ram

% % % Query for mothers
% % ?- mother(X, sita).
% % % Output: X = gita

% % ?- mother(X, raj).
% % % Output: X = gita

% % % Query for siblings
% % ?- sibling(sita, raj).
% % % Output: true

% % ?- sibling(ram, gita).
% % % Output: false

