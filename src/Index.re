module List = Belt.List;
module Document = {
  type t;
  type migration = list(t) => list(t);

  let migrate = (list, fns) => {
    fns->List.reduce(list, (acc, current) => current(acc));
  };
};

type document = {id: string};
let documents = [{id: "0"}, {id: "1"}];

let result =
  documents->Document.migrate([
    documents => documents->List.map(doc => {{id: doc.id ++ "-1"}}),
    documents => documents->List.map(doc => {{id: doc.id ++ "-2"}}),
  ]);