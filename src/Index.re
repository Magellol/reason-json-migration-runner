module List = Belt.List;
module Migration = {
  type migrationFn('a) = list('a) => list('a);

  let migrate = (list: list('a), fns: list(migrationFn('a))) => {
    fns->List.reduce(list, (acc, current) => current(acc));
  };
};

type document = {id: string};
let documents = [{id: "0"}];

let result = documents->Migration.migrate([]);