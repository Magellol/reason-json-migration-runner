type document = {
  id: string,
  foo: option(string),
};

let documents = [{id: "0", foo: Some("bar")}];

let result =
  documents->Migration.migrate([|
  // How can we type migration functions. Each functions are basically a list('a) => list('b) but reason doesn't like the fact that 'a is different from one function to another
  // It's basically a pipeline of the following:
  /**
   * [
   *   'a => 'b,
   *   'b => 'c,
   *   'c => 'd,
   *   ...
   * ]
   * 
   * How can we type this in Reason?
   */
    Migration_001.migrate,
  |]);