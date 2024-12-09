Avec les templates, les méthodes de la classe doivent effectivement être définies directement dans le fichier en-tête (.h). 
Cela signifie que non seulement la déclaration, mais aussi les définitions des méthodes doivent être incluses dans le même fichier.

Pourquoi ?
En C++, les templates sont des classes ou des fonctions générées au moment de la compilation. Cela signifie que le compilateur 
a besoin de connaître l'implémentation complète du template pour chaque type utilisé. 
Si les définitions sont dans un .cpp, elles ne seront pas visibles lorsque le template est instancié avec un type spécifique 
dans un autre fichier.