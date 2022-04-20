* a simple c++ reflection framework


* Configrue & build

```
git clone https://github/Clucheng/reflection_json
mkdir build && cd build
cmake ..
```


* example
```
  using JsonRefelction = details::JsonRefelction<details::JsonBase<details::JsonCPP>>;
  Persons persons;
  persons.arr.push_back(Person{"Rose", 24, false});
  persons.arr.push_back(Person{"Jack", 25, true});

  auto value = JsonRefelction::to_json<Persons>(persons);
  auto ref_b = JsonRefelction::from_json<Persons>(value);
  std::cout << JsonRefelction::to_string(value) << std::endl;
```

* result
```
{
        "arr" :
        [
                {
                        "age" : 24,
                        "is_male" : false,
                        "name" : "Rose"
                },
                {
                        "age" : 25,
                        "is_male" : true,
                        "name" : "Jack"
                }
        ]
}
```

