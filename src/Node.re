[@bs.val] external __dirname: string = "__dirname";

module Fs = {
  [@bs.deriving jsConverter]
  type encoding = [ | `utf8];

  [@bs.module "fs"]
  external fs_readdirSync: (string, string) => string = "readdirSync";

  let readdirSync = (path: string, encoding: encoding) => {
    fs_readdirSync(path, encodingToJs(encoding));
  };
};

module Path = {
  [@bs.module "path"] [@bs.variadic]
  external resolve: array(string) => string = "resolve";
};