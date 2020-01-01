module List = Belt.List;
module Migration = {
  type migrationFn('a) = list('a) => list('a);

  let migrate = (list: list('a), fns: list(migrationFn('a))) => {
    fns->List.reduce(list, (acc, current) => current(acc));
  };
};

type document = {
  id: string,
  foo: option(string),
};

let documents = [{id: "0", foo: Some("bar")}];

let result =
  documents->Migration.migrate([
    json => json->List.map(doc => {{id: doc.id ++ "-migration1", foo: None}}),
    json => json->List.map(doc => {{id: doc.id ++ "-migration2", foo: Some(doc.id)}}),
  ]);

Js.log(result);