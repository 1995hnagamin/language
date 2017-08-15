#[macro_use]
extern crate nom;

use nom::{IResult, space, alpha};

named!(name_parser<&str>,
       chain!(
           tag!("Hello,") ~
           space? ~
           name: map_res!(
               alpha,
               std::str::from_utf8
            ) ~
           tag!("!"),

           || name
    )
);

fn main() {
    match name_parser("Hello, world!".as_bytes()) {
        IResult::Done(_, name) => println!("name = {}", name),
        IResult::Error(error) => println!("Error: {:?}", error),
        IResult::Incomplete(needed) => println!("Incomplete: {:?}", needed),
    }
}

#[test]
fn test_name_parser() {
    let empty = &b""[..];
    assert_eq!(name_parser("Hello, Rust!".as_bytes()), IResult::Done(empty, "Rust"));
    let remain = &b" How are you."[..];
    assert_eq!(name_parser("Hello, nom! How are you.".as_bytes()), IResult::Done(remain, "nom"));
}
