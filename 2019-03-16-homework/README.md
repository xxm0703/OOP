# Игри с карти (първа част)

Целта на цялата задача ще бъде да се имплементира програма, която чете тесте карти от стандартния вход, и извършва операции с тестетата. (Подобна на тази от първия срок.)

В първата част на задачата ще трябва да се имплементират само класовете за тестета, карти и ръце.

**Не необходимо да имплементирате main функция, или каквито и да е било методи и класове за изпълнение на команди/операции.**

## Програмен интерфейс (API)

Програмният интерфейс (API) на една библиотека обикновено наричаме декларацията на всички публични класове и методи. В Java това става в интерфейси, а в случая имаме и два изброими типа – всички те се намират в пакета `org.elsys.cardgame.api`:
 * `Card` – интерфейс за карта; съдържа методи за достъп до ранг и боя
 * `Deck` – интерфейс за тесте; съдържа методи за достъп до всички карти от тестето, размер, размер на ръката, сщо и методи за раздаване, теглене, сортиран и размесване на карти
 * `Hand` – интерфейс за ръка; съдържа методи за достъп до картите в ръката, както и за броя им
 * изброимите типове в пакета са `Rank` (ранг на карта) и `Suit` (боя на карта).

За всеки от трите интерфейсите трябва да предоставите имплементации (класове, които ги имплементират), така че jUnit тестовете да минават.

## Тестета за война, белот и сантасе

В класа `DeckFactory` трябва да имплементирате трите метода, които създават тестета съответно за война, белот и сантасе. И трите метода връщат тип `Deck`, така че единственото задължително условие е класът, който ще върнат, да наследява `Deck`. Могат да се изберат различни подходи – да направите само един наследник и да връщате него в трите метода или да направите отделни класове за различните тестета с общ абстрактен родителски клас. Това преценете сами.

В първоначалното си състояние картите в тестетата трябва да са подредени във възходящ ред от най-слабата към най-силната. Т.е. раздавайки или теглейки картите „отгоре надолу“ теглите от първата (най-слабата) към последната (най-силната). При сортиране картите следва да се подредят в описания ред.

Следват детайли за различните игри.

### Сила на боите

Тя е еднаква за всички игри и е както следва (в нарастващ ред): clubs, diamonds, hearts, spades.

### Детайли за война

*   Рангове в нарастващ ред - `2 3 4 5 6 7 8 9 10 Jack Queen King Ace`
*   Общ брой карти - 52
*   Брой карти в ръка - 26 (тук `deal` ще върне ръка с първите 26 карти от колодата)

### Детайли и команди, специфични за белот

*   Рангове в нарастващ ред - `7 8 9 Jack Queen King 10 Ace`
*   Общ брой карти - 32
*   Брой карти в ръка - 8 (тук `deal` ще върне ръка с първите 8 карти от колодата)

### Детайли и команди, специфични за сантасе

*   Рангове в нарастващ ред - `9 Jack Queen King 10 Ace`
*   Общ брой карти - 24
*   Брой карти в ръка - 6 (тук `deal` ще върне ръка с първите 6 карти от колодата)

## Тестове

Преди да пускате тестовете, разгледайте кода им, така че да може лесно да се ориентирате в тях, когато някой тест не ви минава.

Има един абстрактен тест клас `AbstractDeckTest`, от който наследяват останалите. На практика всички `@Test` методи са в него, като наследниците просто имплементират абстрактни методи, които `AbstractDeckTest` използва – това са методи за създаване на тесте, размер на тестето и ръката, както и методи, който връща подредба на картите.

## Предаване

Срокът за предаване е 16.03.2018 20:00 в moodle.

Не забравяйте, че домашното ще има и втора част.
