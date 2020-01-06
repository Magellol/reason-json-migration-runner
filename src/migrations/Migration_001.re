module List = Belt.List;

type document1 = {id: string};
type document2 = {id: string};

let migrate = docs => docs->List.map(doc => {{id: doc.id ++ "001"}});