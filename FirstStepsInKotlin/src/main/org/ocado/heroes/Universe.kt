package org.ocado.heroes

class Universe {
    private val deadVillains = ArrayList<SuperVillain>()
    private val characters = HashMap<Character, Int>()

    fun actNasty(villain: SuperVillain) {
        incrementer(villain)
    }

    fun beat(hero: SuperHero, villain: SuperVillain) {
        incrementer(hero)

        val villainPoints: Int = characters.getValue(villain)
        val heroPoints: Int = characters.getValue(hero)

        if (heroPoints > villainPoints) {
            deadVillains.add(villain)
        }

    }

    fun addCharacter(character: Character): Boolean {

        characters[character] = characters[character]?.let { return false } ?: 0

        // TODO
        return false
    }

    private fun incrementer(character: Character) {
        val count = characters.getValue(character) + 1
        characters[character] = count
    }
}