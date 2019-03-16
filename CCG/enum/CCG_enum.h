#ifndef CCG_ENUM_H
#define CCG_ENUM_H

enum class Occurence// "enum class" defines this as a scoped enumeration instead of a standard enumeration
{
    STANDARD,
    EXCELLENT,
    RARE,
    LEGENDS,
    GOD,
    MAX_RARE // RED is inside the scope of Color

};

enum class CardType
{
    CREATURE,
    MAGIC,
    CURSE,
    MAX_TYPE
};

enum class RaceType
{
    OCEAN,
    GROUND,
    UNDERGROUND,
    SKY,
    OUT_OF_SKY,
    UNDEAD,
    MAX_RACE_TYPE
};

enum class RaceKind
{
    FISH,
    HUMAN,
    ORC,
    GOBLIN,
    DRAGON,
    GHOST,
    MACHINE,
    BRID,
    LIZARD,
    MURLOC,
    MAX_RACE_KIND
};

enum class PropertyType
{
    WATER,
    SOLAR,
    FIRE,
    FAIRY,
    GOD,
    EARTH,
    METAL,
    MAGNETIC,
    MOON,
    DRAGON,
    FOREST,
    THUNDER,
    WIND,
    LIGHT,
    DARK,
    MAX_PROPERTY_TYPE

};

enum class ConsumeType
{
    LIFE,
    MAGE,
    MAX_CONSUME_TYPE
};

#endif // CCG_ENUM_H


