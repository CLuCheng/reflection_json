* a simple c++ reflection framework


* Configrue & build

```
git clone https://github/Clucheng/reflection_json
cd reflection_json
cmake -B build
```


* example
```
  using JsonReflection = details::JsonReflection<details::JsonBase<details::JsonCPP>>;
  Persons persons;
  persons.arr.push_back(Person{"Rose", 24, false});
  persons.arr.push_back(Person{"Jack", 25, true});

  auto json_value = JsonReflection::to_json<Persons>(persons);
  auto value = JsonReflection::from_json<Persons>(json_value);
  std::cout << JsonReflection::to_string(json_value) << std::endl;
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

