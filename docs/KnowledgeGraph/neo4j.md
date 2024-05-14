> https://zhuanlan.zhihu.com/p/88745411 快速入门

Cypher is Neo4j’s declarative graph query language. 

:play start

:clear

:history

:use system 切换数据库

```cypher
MATCH (n) DETACH DELETE n
CREATE (n:Person {name:'John'}) RETURN n
//CREATE是创建操作，Person是标签，代表节点的类型。花括号{}代表节点的属性
CREATE (a:Person {name:'Todd'})-[r:FRIENDS]->(b:Person {name:'Carlos'})；
MATCH (a:Person {name:'Liz'}), (b:Location {city:'Boston'}) 
MERGE (a)-[:BORN_IN {year:1981}]->(b)；

MATCH (a:Person {name:'Liz'}) SET a.age=34              
MATCH (a:Location {city:'Portland'}) DELETE a
MATCH (a:Person {name:'Mike'}) REMOVE a.test
```
