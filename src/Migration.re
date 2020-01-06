module Array = Belt.Array;
type next('a) = list('a) => list('a);

let migrate = (list: list('a), fns: array(next('a))) => {
  fns->Array.reduce(list, (acc, current) => current(acc));
};