+-------------------------------------------------------------------------------------------
|  Compilation
+-------------------------------------------------------------------------------------------

Au niveau le plus haut (imm2122-gr2)
	Compilation, produit l'exécutable ./dames
	  $ make
	Tests : compile et exécute les tests sous
	  ./ tests
 	$ make tests
       Docs : production des docs sous ./ docs
 	  $ make docs
 
+-------------------------------------------------------------------------------------------
|  Utilisation
+-------------------------------------------------------------------------------------------

$ ./dames --pvp			Pour activer le mode joueur contre joueur

$ ./dames --port port			créer un serveur  (Jouer en tant que hôte)	

$./dames  --connect			ip:port : se connecter au serveur (Jouer en tant que client)
