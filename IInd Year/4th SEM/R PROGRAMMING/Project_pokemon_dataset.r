read.csv("C:/Users/pc/OneDrive/Documents/pokemon.csv") -> pokemon
View(pokemon)


#checking number of rows and columns
nrow(pokemon)
ncol(pokemon)

#tabulation of categorical columns
table(pokemon$is_legendary)table(pokemon$generation)
table(pokemon$type1)

#min-max hp
min(pokemon$hp)
max(pokemon$hp)

min(pokemon$speed)
max(pokemon$speed)

#checking missing values
is.na(pokemon$abilities)
sum(is.na(pokemon$abilities))

#renaming columns
colnames(pokemon)[colnames(pokemon) == 'type1'] <- "Primary_Type"
colnames(pokemon)[colnames(pokemon) == 'type2'] <- "Secondary_Type"
colnames(pokemon)[colnames(pokemon) == 'name'] <- "Pokemon_name"



#--------------------------------------------------------------------------

#grass-pokemon
grass_pokemon <- subset(pokemon,Primary_Type=="grass") 

min(grass_pokemon$speed)
max(grass_pokemon$speed)

mean(grass_pokemon$sp_attack)
mean(grass_pokemon$sp_defense)


#visualizing stats of grass-pokemon
library(ggplot2)

#hp
ggplot(data = grass_pokemon,aes(x=hp)) + geom_histogram()
ggplot(data = grass_pokemon,aes(x=hp)) + geom_histogram(fill= 'palegreen4')


#height
ggplot(data = grass_pokemon,aes(x=height_m)) + geom_histogram()


#weight
ggplot(data = grass_pokemon,aes(x=weight_kg)) + geom_histogram()


#legendary vs not-legendary
ggplot(data = grass_pokemon,aes(x=is_legendary)) + geom_bar()


#--------------------------------------------------------------------------

#fire-Pokemon
fire_pokemon <- subset(pokemon,Primary_Type == "fire")

min(fire_pokemon$speed)
max(fire_pokemon$speed)

mean(fire_pokemon$sp_attack)
mean(fire_pokemon$sp_defense)


#visualizing stats of fire-pokemon

#generation
ggplot(data = fire_pokemon,aes(x=generation,fill=as.factor(generation))) + geom_bar()


#Secondary_Type
ggplot(data = fire_pokemon,aes(x=Secondary_Type,fill=Secondary_Type)) + geom_bar()


#sp_attack vs sp_defense
ggplot(data = fire_pokemon,aes(x=sp_attack,y=sp_defense)) + geom_point(col="coral")


#height vs weight
ggplot(data = fire_pokemon,aes(x=height_m,y=weight_kg)) + geom_point()


#--------------------------------------------------------------------------

#water-Pokemon
water_pokemon <- subset(pokemon,Primary_Type == "water")

min(water_pokemon$speed)
max(water_pokemon$speed)

mean(water_pokemon$sp_attack)
mean(water_pokemon$sp_defense)


#visualizing stats of Water-pokemon

#Against Ice
ggplot(data = water_pokemon,aes(x=against_ice)) + geom_histogram(fill='cadetblue3')


#Against poison
ggplot(data = water_pokemon,aes(x=against_poison)) + geom_histogram(fill='blueviolet')


#Against Grass
ggplot(data = water_pokemon,aes(x=against_grass)) + geom_histogram(fill='chartreuse4')



#--------------------------------------------------------------------------
#pyschic pokemon

psychic_pokemon <- subset(pokemon,Primary_Type == "psychic")

min(psychic_pokemon$speed)
max(psychic_pokemon$speed)

mean(psychic_pokemon$sp_attack)
mean(psychic_pokemon$sp_defense)


#visualizing stats of psychic-pokemon
ggplot(data = psychic_pokemon,aes(x=base_total)) + geom_histogram(fill='darkorchid')

ggplot(data = psychic_pokemon,aes(x=as.factor(generation),y=sp_defense)) + geom_boxplot(fill='darkorchid4')

ggplot(data = psychic_pokemon,aes(x=is_legendary)) + geom_bar(fill='darkorchid2')















