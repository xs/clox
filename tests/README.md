# testlox

How to use the Lox test suite for your interpreter!

# Getting Set Up

1. Install [Dart](https://dart.dev/get-dart) (**note** the latest version is 3, but you need to install 2)
2. Copy this folder into your project as `test`
3. Run `dart pub get` from within this folder
4. Copy the contents of the [lox test suite](https://github.com/munificent/craftinginterpreters/tree/master/test) into this folder

# Running the Tests

There are instructions in the Crafting Interpreters repo on [using the test suite and runner to test your own implementation](https://github.com/munificent/craftinginterpreters#testing-your-implementation). TL;DR run this from your repo's root:

```
dart test/test.dart <suite> --interpreter <binary>
```

- `suite` is the test suite you want to run. For example, to run the suite for chapter 4 (scanning), call it with `chap04_scanning`. There's a list of suites in the `test.dart` file
- `binary` is the path to your interpreter. If your interpreter needs additional arguments, you can pass them with `--arguments <arguments>`, but I couldn't get that working.
