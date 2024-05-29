% Facts
male(ram).
male(raj).
female(sita).
female(gita).

parent(ram, sita).
parent(ram, raj).
parent(gita, sita).
parent(gita, raj).

% Rules
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% % Queries
% % Query for fathers
% ?- father(X, sita).
% % Output: X = ram

% ?- father(X, raj).
% % Output: X = ram

% % Query for mothers
% ?- mother(X, sita).
% % Output: X = gita

% ?- mother(X, raj).
% % Output: X = gita

% % Query for siblings
% ?- sibling(sita, raj).
% % Output: true

% ?- sibling(ram, gita).
% % Output: false
