-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Client: localhost
-- Généré le: Lun 10 Novembre 2014 à 17:58
-- Version du serveur: 5.5.24-log
-- Version de PHP: 5.3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données: `test`
--

-- --------------------------------------------------------

--
-- Structure de la table `identite`
--

CREATE TABLE IF NOT EXISTS `identite` (
  `id_element` int(10) NOT NULL DEFAULT '0',
  `parent_id` int(10) DEFAULT NULL,
  `name` text COLLATE utf8_bin,
  `url` varchar(281) COLLATE utf8_bin DEFAULT NULL,
  `development` text COLLATE utf8_bin,
  `picture` text COLLATE utf8_bin
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Contenu de la table `identite`
--

INSERT INTO `identite` (`id_element`, `parent_id`, `name`, `url`, `development`, `picture`) VALUES
(34725, NULL, 'Enceinte de Penn-ar-Lan', 'http://fr.topic-topos.com/enceinte-de-penn-ar-lan-ouessant', 'Cette enceinte est composée de petits menhirs et date environ de 2000 av. J.-C. Elle est bâtie selon un plan elliptique et paraît reliée à un système plus complexe, en partie disparu. Son tracé et son orientation semblent indiquer qu''elle était destinée à des observations du ciel.','./res/Textures/_BATIMENTS/enceinte-de-penn-ar-lan-ouessant.png'),
(34726, NULL, 'Vestiges du château d’Arlan', 'http://fr.topic-topos.com/vestiges-du-chateau-darlan-ouessant', 'Il ne reste que peu d''éléments du château d''Ouessant : le plan grossièrement triangulaire est encore visible, ainsi que les traces de deux tours de la façade est. Cet édifice occupait un site défensif, déjà aménagé à l''époque gallo-romaine, dans l''isthme de la presqu''île d''Arlan et à la verticale d''un mouillage relativement abrité. La tradition locale prétend que le seigneur voulait apercevoir Brest du haut de ses tours. Les Ouessantins requis pour construire le château se révoltèrent et lapidèrent le seigneur qui dut s''enfuir. Le bâtiment était déjà en ruine au XVI<SUP>e</SUP> siècle.', './res/Textures/_BATIMENTS/vestiges-du-chateau-darlan-ouessant.png'),
(34727, NULL, 'Phare du Stiff', 'http://fr.topic-topos.com/phare-du-stiff-ouessant', 'La construction d''un fanal à Ouessant fait, dans un premier temps, partie d''un projet de mise en défense de 1681. Abandonné, il est repris plus tard, sans arrière-plan stratégique. Deux phares sont alors nécessaires pour signaler l''entrée de la Manche aux navires venant du grand large et doivent être différenciés du feu des Scilly à la pointe de Cornouaille. Cette tour à feu, en fait deux tours accolées l''une à l''autre, est l''un des plus vieux phares de France. Le feu s''allume à partir d''un brasero, situé sur la terrasse supérieure du phare, et brûle du bois et du charbon. Modifié à plusieurs reprises, l''édifice possède en 1831 une optique de feu fixe de premier ordre. En 1926, il est équipé d''un système donnant deux éclats rouges toutes les 20 secondes, et la portée en est de 23 milles. Le feu est situé à 89,1 mètres au-dessus de la mer.','./res/Textures/_PHARES/phare-du-stiff-ouessant.png'),
(34728, NULL, 'Kroaz ar Chalvar', 'http://fr.topic-topos.com/kroaz-ar-chalvar-ouessant', 'Cette croix, dont la date d''édification est gravée sur le socle, était décorée lors du pardon de Saint-Paul-Aurélien, le 29 mars. Les gens du voisinage la recouvraient de dessus-de-lit ornés de feuillages et disposaient des tableaux contenant des images de piété sur les degrés du socle. Une source, liée au culte de saint Paul-Aurélien, se trouve sur la grève, au pied du calvaire. À proximité, une trace visible serait, d''après la légende, celle du genou du saint.','./res/Textures/_RELIGION/kroaz-ar-chalvar-ouessant.png'),
(34729, NULL, 'Ancien siège du gouvernement', 'http://fr.topic-topos.com/ancien-siege-du-gouvernement-ouessant', 'Cette demeure abritait le gouvernement d''Ouessant après l''acquisition de l''île par Louix XV en 1764. Avant son réaménagement dans les années 1970, elle conservait plusieurs caractéristiques de l''architecture militaire du XVIII<SUP>e</SUP> siècle, qui se retrouvent dans un certain nombre de constructions, tant en métropole que dans les départements d''outre-mer : encadrement de fenêtre en bois, parquet de pitchpin de 2,5 pouces, lambris au rez-de-chaussée et escalier à balustres plats.','./res/Textures/_BATIMENTS/ancien-siege-du-gouvernement-ouessant.png'),
(34730, NULL, 'Maison du Niou', 'http://fr.topic-topos.com/maison-du-niou-ouessant', 'Cette maison est typique de l''architecture rurale de l''île. Les maisons sont en général regroupées en hameaux au centre d''un terroir agricole. Elles ne comportaient qu''un niveau d''habitation sous un toit de chaume, mais certaines d''entre elles ont été surélevées dès la fin du XIX<SUP>e</SUP> siècle, ou délaissées pour des demeures à étage et à toit d''ardoises. La maison est généralement orientée est-ouest, la façade principale au sud et un pignon aveugle à l''ouest,afin qu''elle soit protégée des bourrasques venues de la mer. Les parcelles des différentes maisons, tachennou, sont elles-mêmes regroupées au sein d''ensembles, mezadou, autrefois exploités collectivement. Ouessant comporte plus de 55 000 parcelles réparties entre les 1 560 hectares de superficie de l''île.','./res/Textures/_NIOU/maison-du-niou-ouessant.png'),
(34731, 34730, 'Penn Brao', 'http://fr.topic-topos.com/penn-brao-ouessant', 'L''aménagement des maisons d''Ouessant utilise l''espace domestique comme s''il s''agissait de bateaux. Les meubles forment les cloisons et sont disposés le long de deux couloirs se croisant au centre de la maison. Les aires de stockage pour les récoltes et de conservation pour la nourriture occupent l''espace central. La demeure possède deux pièces. L''une, appelée penn ludu, extrémité des cendres, ou penn lous, extrémité sale, sert de cuisine, de lieu de réunion et de travail. La seconde pièce, penn brao, belle extrémité, est utilisée lors des grandes occasions et sert, éventuellement, de chambre à coucher. Les meubles, fabriqués en bois récupéré sur la grève, sont en général peints en bleu et blanc.','./res/Textures/_NIOU/penn-brao-ouessant.png'),
(34732, 34730, 'Cheminée', 'http://fr.topic-topos.com/cheminee-ouessant', 'Cette cheminée, enfermée dans un placard, est d''un type qui se retrouve fréquemment sur l''île, et permet d''éviter les courants d''air.','./res/Textures/_NIOU/cheminee-ouessant.png'),
(34733, 34730, 'Puits de la maison du Niou', 'http://fr.topic-topos.com/puits-de-la-maison-du-niou-ouessant', 'La maison est le centre d''une petite exploitation agricole dont les différents éléments, comme ce puits, se répartissent dans des enclos entourant l''habitation.','./res/Textures/_NIOU/puits-de-la-maison-du-niou-ouessant.png'),
(34734, 34730, 'Crèche', 'http://fr.topic-topos.com/creche-ouessant', 'Ce bâtiment possède un toit à couverture d''argile. À l''origine, les maisons d''Ouessant étaient couvertes de chaume. La paille de seigle était lestée d''un peu d''argile, ce qui rendait le toit résistant aux vents violents fréquents sur l''île en hiver. L''ardoise a remplacé le chaume sur les maisons. Les mottes de gazon, taouarc''h, sont posées sur un lit de fougères et de ronces, à même la charpente, puis recouvertes d''une épaisse couche d''argile parfois mélangée à de la balle d''avoine ou à de la paille hachée.','./res/Textures/_NIOU/creche-ouessant.png'),
(34735, 34730, 'Costume de mariée (1880)', 'http://fr.topic-topos.com/costume-de-mariee-1880-ouessant', 'Le costume des femmes d''Ouessant est un assemblage de plusieurs éléments épinglés. La jupe, broz, est portée en général sur deux lourds jupons de drap de couleur bleu et rouge. Peu à peu, la coutume a fait que seul l''un des deux était porté avec un petit galon de tissu de la couleur complémentaire. Le justinen est un corsage de tissu léger sur lequel sont montés les manches et le kamproz, le corselet retenu par des bretelles. Le châle, mouchoar, le dépassant, la petite pièce d''étoffe bordant le châle sur le devant, riblikenn, et le tablier, tancher, complètent l''ensemble. Ce costume est porté jusque dans les années 1960 et a évolué en fonction des modes. Il existe ainsi un costume « charleston » dans les années 1925. Les étoffes se sont allégées, la jupe a découvert le bas des jambes, la coiffe a rétréci pour laisser voir la chevelure vers 1910. La mariée, dont le costume comporte un châle en indienne, porte le ruban des Enfants de Marie, ainsi qu''une croix et un cœur en métal doré.','./res/Textures/_NIOU/costume-de-mariee-1880-ouessant.png'),
(34736, NULL, 'Costume de mariée', 'http://fr.topic-topos.com/costume-de-mariee-ouessant', 'Ce costume de mariée date du XX<sup>e</sup> siècle. En effet, le blanc n''est intervenu que très progressivement dans la composition du costume, vers 1950.','./res/Textures/_NIOU/costume-de-mariee-xxesiecle-ouessant.png'),
(34737, NULL, 'Croix de proella', 'http://fr.topic-topos.com/croix-de-proella-ouessant', 'Cette petite croix est remise aux familles qui ont perdu l''un des leurs en mer. Elle est placée sur la table du penn brao et veillée comme s''il s''agissait du défunt en personne. Le lendemain, un prêtre procède à la levée du corps, qui est mené à l''église et déposé, après une messe, dans une urne spéciale.','./res/Textures/_RELIGION/croix-de-proella-ouessant.png'),
(34738, NULL, 'Réflecteurs de phare', 'http://fr.topic-topos.com/reflecteurs-de-phare-ouessant', 'Ces réflecteurs se composent d''une surface en métal poli et sont destinés à réfléchir les rayons dans la direction choisie afin de permettre aux navires de se situer. Le navigateur doit pouvoir s''orienter mais également identifier le phare, c''est pourquoi les appareils optiques ne sont pas tous semblables.','./res/Textures/_PHARES/reflecteurs-de-phare-ouessant.png'),
(34739, 34738, 'Lampe à huile', 'http://fr.topic-topos.com/lampe-a-huile-ouessant', 'Augustin Fresnel (1788-1827) avait hiérarchisé les phares, en fonction de leur puissance, et déterminé ainsi cinq catégories. Les plus puissants, de premier ordre, étaient équipés de lampes à cinq mèches. Le perfectionnement des optiques et le souci d''augmenter la portée lumineuse ont conduit à doter les phares de lampes comportant jusqu''à huit mèches concentriques.','./res/Textures/_PHARES/lampe-a-huile-ouessant.png'),
(34740, 34738, 'Optique à éclats réguliers', 'http://fr.topic-topos.com/optique-a-eclats-reguliers-ouessant', 'Cet appareil, à éclat toutes les 30 secondes, illustre l''évolution technique permettant le remplacement de l''ancien système optique composé de miroirs concaves. Il s''agit là de prismes à réflexion totale, catadioptrique. Avec ce type d''appareil, tournant sur un tambour de galets coniques en bronze, la révolution était d''une durée de 8 minutes.','./res/Textures/_PHARES/optique-a-eclats-reguliers-ouessant.png'),
(34741, 34738, 'Maquette du phare Amédée', 'http://fr.topic-topos.com/maquette-du-phare-amedee-ouessant', 'Le secteur industriel lié aux phares s''est développé pendant le XIX<SUP>e</SUP> siècle. Les entreprises concernées prenaient en charge le service des phares et l''exportation. La construction de tours dans des pays lointains et souvent sous-équipés a très vite demandé des techniques et des moyens nouveaux. La construction métallique permettait de résoudre facilement les problèmes posés par l''éloignement, le manque de matériaux et de main-d''œuvre qualifiée. Le phare prévu pour l''îlot Amédée en Nouvelle-Calédonie a d''abord été monté à Paris, à l''occasion de l''Exposition universelle de 1865, puis démonté et transporté sur son emplacement définitif par voie de mer. Il est l''œuvre de l''ingénieur Rigollet. Un phare semblable, de structure métallique, a été érigé sur le plateau des Roches-Douvres, entre Paimpol et Guernesey.','./res/Textures/maquette-du-phare-amedee-ouessant.png'),
(34742, 34738, 'Ampoule', 'http://fr.topic-topos.com/ampoule-ouessant', 'Ce type d''ampoule à 6 kW/127 V a équipé le phare du Stiff jusqu''à ce qu''elle soit remplacée par des ampoules de bas voltage.','./res/Textures/_PHARES/ampoule-ouessant.png'),
(34743, 34738, 'Maquette du phare de Cordouan', 'http://fr.topic-topos.com/maquette-du-phare-de-cordouan-ouessant', 'Cette maquette reproduit le phare situé sur un rocher du golfe de Gascogne, au large de l''estuaire de la Gironde, sur le vestige d''un littoral submergé. La construction du phare, dit tour de Cordouan, a débuté en 1584 et a été achevée en 1610. Le foyer se trouve à une hauteur de 63 mètres.','./res/Textures/maquette-du-phare-de-cordouan-ouessant.png'),
(34744, NULL, 'Sémaphore de Créac’h', 'http://fr.topic-topos.com/semaphore-de-creach-ouessant', 'L''entrée de la Manche constitue une importante voie maritime : chaque année, plus de 50 000 navires empruntent le « rail de navigation d''Ouessant ». La surveillance de ce trafic incombe en premier lieu à la tour-radar du Stiff, construite après le naufrage de l''Amoco-Cadiz, mais la Marine nationale, qui a la charge de cette surveillance, a agrandi et surélevé l''ancien sémaphore de Créac''h, jusqu''alors tapi dans les rochers au pied du phare de Créac''h.','./res/Textures/_PHARES/semaphore-de-creach-ouessant.png'),
(34745, NULL, 'Puits de Toulalan', 'http://fr.topic-topos.com/puits-de-toulalan-ouessant', 'Jusqu''à l''aménagement des réserves d''eau sur le ruisseau du Stang-ar-Maedry, Ouessant s''est approvisionné aux nombreux puits et fontaines disséminés sur l''île. Lorsque la nappe phréatique ne pouvait être atteinte, l''eau de pluie était récupérée sur les toitures et guidée vers les citernes placées à proximité des maisons.','./res/Textures/_NIOU/puits-de-toulalan-ouessant.png'),
(34746, NULL, 'Port de Bougezenn', 'http://fr.topic-topos.com/port-de-bougezenn-ouessant', 'L''île, exposée aux vents du secteur ouest dans la baie de Lampaul, n''a jamais constitué un abri suffisamment sûr pour qu''un port de pêche puisse s''y développer. Toutefois, des havres, situés au pied des falaises et abrités des vents dominants par des protections naturelles « des presqu''îles rocheuses », ont permis, par endroits, l''aménagement de petits ports susceptibles d''abriter quelques barques. Le port de Bougezenn, sur la côte sud de la pointe de Loqueltas, est l''un d''entre eux. Un treuil permettait de hisser les barques jusqu''à une plate-forme afin qu''elles soient tenues à l''abri pendant les tempêtes d''hiver.','./res/Textures/_PORTS/port-de-bougezenn-ouessant.png'),
(34747, NULL, 'Ancienne manutention', 'http://fr.topic-topos.com/ancienne-manutention-ouessant', 'Ce bâtiment est celui de l''ancienne intendance militaire d''Ouessant.','./res/Textures/_BATIMENTS/ancienne-manutention-ouessant.png'),
(34748, NULL, 'Moulin de Karaes', 'http://fr.topic-topos.com/moulin-de-karaes-ouessant', 'Une centaine de petits moulins existaient encore à Ouessant au début du XX<SUP>e</SUP> siècle. Ils servaient, au cours du XIX<SUP>e</SUP> siècle, à pallier l''insuffisance des grands moulins, qui obligeait les Ouessantins à faire moudre leur orge sur le continent. Le décret pris sur le bornage en 1852, interdisant aux barques de pêche de transporter des produits alimentaires, et la venue sur l''île de tailleurs de pierre du Cap-Sizun pour la construction du phare et de l''église paroissiale favorisèrent l''émergence et le développement de ces petits moulins. Celui de Karaes est le seul conservé dans la commune.','./res/Textures/_NIOU/moulin-de-karaes-ouessant.png'),
(34749, NULL, 'Chapelle Notre-Dame-d’Espérance', 'http://fr.topic-topos.com/chapelle-notre-dame-desperance-ouessant', 'Placée sous le double patronage de saint Pierre et de Notre-Dame d''Espérance, cette chapelle est reconstruite en 1854. De plan rectangulaire, elle possède des vitraux de P. Toulhoat représentant la vie de la Vierge.','./res/Textures/_RELIGION/chapelle-notre-dame-desperance-ouessant.png'),
(34750, NULL, 'Église Saint-Paul-Aurélien', 'http://fr.topic-topos.com/eglise-saint-paul-aurelien-ouessant', 'Cette église est dédiée au premier évêque du Léon, qui fait escale à Ouessant et y établit un monastère, Lampaul, avant de se fixer sur le continent. Elle remplace deux églises antérieures, détruites en raison de leur état de délabrement. La flèche du clocher a été offerte par la Couronne britannique à la suite du naufrage du Drummond-Castle, le 17 juin 1896, au large des côtes de l''île.','./res/Textures/_RELIGION/eglise-saint-paul-aurelien-ouessant.png'),
(34751, 34750, 'Sainte Barbe', 'http://fr.topic-topos.com/sainte-barbe-ouessant', 'Cette statue était autrefois accompagnée d''une tour, attribut de la sainte et symbole du lieu où elle aurait été enfermée et aurait subi son martyre. La statue a été rebaptisée Marie Madeleine.','./res/Textures/_RELIGION/sainte-barbe-ouessant.png'),
(34752, 34750, 'Urne des proellas', 'http://fr.topic-topos.com/urne-des-proellas-ouessant', 'Cette urne, placée près de l''autel du Rosaire, recueillait les croix des proellas. Ces croix symbolisaient les marins morts en mer, et dont les corps n''avaient pas été retrouvés. Le terme de proella désigne à la fois la croix en cire, le disparu et la cérémonie funèbre. Lorsque l''urne est remplie, les croix sont transférées dans un petit ossuaire. Cette pratique existait dès le XVIII<SUP>e</SUP> siècle et a perduré jusqu''en 1962.','./res/Textures/_RELIGION/urne-des-proellas-ouessant.png'),
(34753, 34750, 'Tombe', 'http://fr.topic-topos.com/tombe-ouessant', 'Les tombes des curés d''Ouessant ou des prêtres originaires de l''île se trouvent dans un enclos à part. Elles sont regroupées autour d''un calvaire édifié en 1884 à la suite d''une mission.','./res/Textures/_RELIGION/Tombe-ouessant.png'),
(34754, NULL, 'Tombes de naufragés', 'http://fr.topic-topos.com/tombes-de-naufrages-ouessant', 'Ces tombes sont celles des naufragés du Drummond-Castle, qui a sombré le 17 juin 1896, en quelques minutes, dans le passage du Fromveur, après avoir touché une tête de roche. Sur les 247 passagers et membres d''équipage, seules 3 personnes furent sauvées. Les corps retrouvés reçurent une sépulture à Ouessant ou à Molène. La Castle Mail Packet, qui armait le navire, et différentes fondations anglaises, touchées par la sollicitude des Ouessantins, ont fait don du clocher de l''église Saint-Paul-Aurélien à Ouessant.','./res/Textures/_RELIGION/Tombes-de-naufrages-ouessant.png'),
(34755, NULL, 'Monument des proellas', 'http://fr.topic-topos.com/monument-des-proellas-ouessant', 'Un rituel particulier à Ouessant est attesté dès le XVIII<SUP>e</SUP> siècle. Un service funéraire, dit pro illa, proella, remplace celui que ne peut avoir un marin disparu en mer. Une petite croix en cire, autrefois en bois, symbolise le disparu. À l''occasion d''une mission ou d''une visite de l''évêque, toutes les croix sont portées au cimetière, dans ce monument qui porte l''inscription suivante : « Ici nous déposons les croix de proella en mémoire de nos marins morts loin de leur pays dans les guerres, les maladies et les naufrages. »','./res/Textures/_RELIGION/monument-des-proellas-ouessant.png'),
(34756, NULL, 'Tour modèle de Roc’h Kromm', 'http://fr.topic-topos.com/tour-modele-de-roch-kromm-ouessant', 'Sous le second Empire, de nombreuses tours similaires ont été construites, tout le long du littoral breton. Le modèle, conçu en 1846, permet d''héberger un corps de troupe chargé de servir une batterie côtière.','./res/Textures/_BATIMENTS/Tour-modele-de-roch-kromm-ouessant.png'),
(34757, NULL, 'Phare de Créac’h', 'http://fr.topic-topos.com/phare-de-creach-ouessant', 'L''ouverture de nombreuses routes maritimes au XIX<SUP>e</SUP> siècle et l''apparition de la locomotion à vapeur permettent aux navires de respecter des horaires plus précis mais les engagent à longer la côte au plus près. Au milieu du XIX<SUP>e</SUP> siècle, 30 000 navires de tout tonnage relèvent Ouessant avant de s''engager dans la Manche ou de se diriger vers une voie transocéanique. Le signalement des dangers liés aux saillants littoraux devient dès lors nécessaire. La construction des phares en France s''est étendue tout au long du XIX<SUP>e</SUP> siècle, 900 tours ont été construites dont un tiers se trouve en Bretagne. Ouessant compte 5 phares et 1 tourelle. Le phare de Créac''h, à l''étude dès 1859, est mis en service en 1863. Électrifié en 1889, il est modernisé à plusieurs reprises. En 1939, une nouvelle optique, éclairée par une lampe à arc à forte luminosité en fait, jusqu''en 1970, le phare le plus puissant du monde. Le Créac''h d''Ouessant pilote ou surveille des phares récemment automatisés comme ceux du Stiff, de Nividic, de La Jument ou des Pierres-Noires. L''ancienne salle des machines abrite désormais un musée retraçant l''histoire des phares.','./res/Textures/_PHARES/phare-de-creach-ouessant.png'),
(34758, NULL, 'Vestiges d’abri de trompette de Porz-Aziou', 'http://fr.topic-topos.com/vestiges-dabri-de-trompette-de-porz-aziou-ouessant', 'Ce bâtiment abrite lors de sa construction la première trompette de brume à air comprimé construite sur les côtes françaises. À l''origine, cette trompette a été conçue pour être actionnée par des chevaux loués sur place. À Ouessant, les chevaux ont été remplacés par une machine à vapeur.','./res/Textures/_PHARES/vestiges-dabri-de-trompette-de-porz-aziou-ouessant.png'),
(34759, NULL, 'Port d’Arlan', 'http://fr.topic-topos.com/port-darlan-ouessant', 'Le môle protège le port d''Arlan des vents de suroît. Ce port est le seul de l''île à être situé vers le sud.','./res/Textures/_PORTS/port-darlan-ouessant.png'),
(34760, NULL, 'Vestiges d’abri de trompette à vapeur', 'http://fr.topic-topos.com/vestiges-dabri-de-trompette-a-vapeur-ouessant', 'En 1885, l''Administration, soucieuse de porter les signaux au plus près des dangers et d''en augmenter la portée, construit à Pern une trompette à vapeur de grande puissance dont le pavillon, long de 5 mètres, pouvait décrire un arc de cercle en pivotant autour de son axe et ainsi balayer l''horizon. Pour alimenter la machine, un impluvium permettait de récolter l''eau de pluie, qui était stockée dans une citerne située sous le bâtiment. Désaffecté en 1900, un nouveau signal ayant été mis en place sur la galerie du phare de Créac''h, l''édifice est acquis par un commerçant de l''île. L''écrivain Bernhardt Kellermann, dans son roman La Mer, le surnomme la « villa des tempêtes ».','./res/Textures/_PHARES/vestiges-dabri-de-trompette-de-porz-aziou-ouessant.png'),
(34761, NULL, 'Chapelle Saint-Gildas', 'http://fr.topic-topos.com/chapelle-saint-gildas-ouessant', 'Cette chapelle est liée au culte de saint Gildas, en breton Gweltaz, qui a donné son nom à la pointe nord-ouest d''Ouessant, Loqueltas. La présence d''une stèle gauloise christianisée semble témoigner de la présence d''un lieu de culte préchrétien. Les parcelles voisines, Ar-Cloistre, Mez-Monaster, indiquent, quant à elles, l''appartenance des lieux à un établissement monastique. Un certain Félix, après avoir été moine à Ouessant, devient au XI<SUP>e</SUP> siècle le réformateur de l''abbaye Saint-Gildas-de-Rhuys (Morbihan). L''édifice a été presque entièrement reconstruit en 1886.','./res/Textures/_RELIGION/chapelle-saint-gildas-ouessant.png'),
(34762, 34761, 'Stèle', 'http://fr.topic-topos.com/stele-ouessant', 'Indiquant un lieu, lec''h, qui est aussi son nom en breton, cette stèle de l''âge du fer a été christianisée au Moyen Âge comme en témoigne la croix gravée au sommet.','./res/Textures/_RELIGION/stele-ouessant.png'),
(34763, 34761, 'Fontaine Saint-Gildas', 'http://fr.topic-topos.com/fontaine-saint-gildas-ouessant', 'Cette construction se rapproche plus de celle d''un puits, avec escalier permettant l''accès à l''eau, que de celle d''une fontaine. Elle appartient à un type de monument qui existe ailleurs dans la commune et sur toute la côte du Léon. Selon la tradition, la fontaine contiendrait neuf pierres dont saint Gildas se serait servi pour lester son bateau.','./res/Textures/_RELIGION/fontaine-saint-gildas-ouessant.png'),
(34764, NULL, 'Pyramide de Runiou', 'http://fr.topic-topos.com/pyramide-de-runiou-ouessant', 'Cette pyramide est un amer, construit à cet endroit en l''absence de tout point remarquable préexistant pour permettre aux navigateurs de faire route en s''alignant sur un point fixe de façon à éviter les dangers.','./res/Textures/_PHARES/pyramide-de-runiou-ouessant.png'),
(34765, NULL, 'Gwasked', 'http://fr.topic-topos.com/gwasked-ouessant', 'Construits comme des étoiles à trois branches, ils permettaient aux animaux de choisir le côté vers lequel se réfugier en fonction du vent. En pierres sèches ou en mottes de gazon, ces abris autrefois nombreux sont désormais plus rares.','./res/Textures/_NIOU/gwasked-ouessant.png'),
(34766, NULL, 'Caserne', 'http://fr.topic-topos.com/caserne-ouessant', 'Au début du XX<SUP>e</SUP> siècle, l''île d''Ouessant a servi de garnison à une compagnie d''hommes de troupe susceptibles d''assurer la défense du lieu en cas d''attaque. Des troupes disciplinaires sont établies dans une île dont la majorité des hommes valides, naviguant au long cours, étaient absents durant de longues périodes. De nombreux désordres, dont certains connurent des suites judiciaires, ont été provoqués par les militaires. Pendant la Seconde Guerre mondiale, les casernes sont occupées par l''armée allemande.','./res/Textures/_BATIMENTS/caserne-ouessant.png'),
(34767, NULL, 'Phare de la jument', 'http://fr.topic-topos.com/phare-de-la-jument-ouessant', 'La construction de ce phare sur la roche de La Jument, au sud-ouest de l''île, a été difficile, et jusqu''en 1903 aucune personne n''avait encore mis le pied à cet endroit. Charles-Eugène Potron, un entomologiste et grand voyageur, lègue à l''État la somme de 400 000 francs-or pour construire une tour dotée des derniers perfectionnements, sur un roc, dans les parages les plus dangereux du littoral atlantique, et cela dans les sept ans, sous peine de voir le legs changer de destinataire. Dans des conditions difficiles, le phare prend place sur le rocher Ar Gazek-Koz, La Vieille-Jument, dans une zone de courants violents. Les travaux sont achevés à temps, mais vingt années supplémentaires sont nécessaires pour consolider l''édifice.','./res/Textures/_PHARES/phare-de-la-jument-ouessant.png'),
(34768, NULL, 'Vestiges de la cloche sous-marine', 'http://fr.topic-topos.com/vestiges-de-la-cloche-sous-marine-ouessant', 'La cloche a été supprimée en 1919.','./res/Textures/_PHARES/vestiges-de-la-cloche-sous-marine-ouessant.png'),
(34769, NULL, 'Phare de Nividic', 'http://fr.topic-topos.com/phare-de-nividic-ouessant', 'Entrepris sur le dernier rocher de la chaussée de Leurvas, à l''ouest de la pointe de Pern, le chantier de Nividic a duré vingt-quatre années. Le phare est conçu d''emblée pour être automatique. L''énergie électrique produite au Créac''h est acheminée par une ligne aérienne qui nécessite la construction de deux pylônes de béton sur les rochers de Conçu et de Kerzu. Une nacelle peut emprunter la même voie pour assurer l''entretien du phare. Le système n''a pas été réutilisé après la Seconde Guerre mondiale. Fonctionnant au gaz jusqu''en 1995, le phare est désormais doté de panneaux solaires qui alimentent un feu scintillant.','./res/Textures/_PHARES/phare-de-nividic-ouessant.png');

-- --------------------------------------------------------

--
-- Structure de la table `localisation`
--

CREATE TABLE IF NOT EXISTS `localisation` (
  `id_element` bigint(20) NOT NULL DEFAULT '0',
  `locality` text COLLATE utf8_bin,
  `latitude` double DEFAULT NULL,
  `longitude` double DEFAULT NULL,
  `epoque` varchar(255) COLLATE utf8_bin DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Contenu de la table `localisation`
--

INSERT INTO `localisation` (`id_element`, `locality`, `latitude`, `longitude`, `epoque`) VALUES
(34725, 'kerlann, Ouessant, France', 48.4566442586706, -5.05937576293945, '-1800000 -2500'),
(34726, 'Kernoas, Ouessant, France', 48.4574411570829, -5.09387969970703, NULL),
(34727, ' Le Stiff, Ouessant, France', 48.4709865162704, -5.06040573120117, '1700 1900'),
(34728, 'Pointe d''Arlan, Ouessant, France', 48.4568719452077, -5.09611129760742, NULL),
(34729, ' Poste, Ouessant, France', 48.4574411570829, -5.09645462036133, '1701 1800'),
(34730, ' Niou-Huella, Ouessant, France', 48.460173285246, -5.11104583740234, '1701 1900'),
(34731, 'Maison du Niou,  Niou-Huella, Ouessant, France', 48.460116367409, -5.11053085327148, '1801 1900'),
(34732, 'Maison du Niou,  Niou-Huella, Ouessant, France', 48.4600879084666, -5.11053085327148, '1701 1900'),
(34733, 'Maison du Niou,  Niou-Huella, Ouessant, France', 48.4601448263355, -5.11057376861572, '1701 1900'),
(34734, 'Maison du Niou,  Niou-Huella, Ouessant, France', 48.4601448263355, -5.11078834533691, '1801 1900'),
(34735, 'Maison du Niou,  Niou-Huella, Ouessant, France', 48.460173285246, -5.11035919189453, NULL),
(34736, ' Musée des Traditions ouessantines, Ouessant, France', 48.4576688400461, -5.09628295898438, '1901 2000'),
(34737, 'Musée des Traditions ouessantines, Ouessant, France', 48.4602871207284, -5.11070251464844, '1901 2000'),
(34738, 'Phare de Créac''h, Ouessant, France', 48.4544811856389, -5.08769989013672, '1901 2000'),
(34739, 'Réflecteurs de phare, Phare de Créac''h, Ouessant, France', 48.4549650389239, -5.08830070495605, NULL),
(34740, 'Réflecteurs de phare, Phare de Créac''h, Ouessant, France', 48.4547942677028, -5.08808612823486, NULL),
(34741, 'Réflecteurs de phare, Phare de Créac''h, Ouessant, France', 48.4549365770936, -5.08825778961182, NULL),
(34742, 'Réflecteurs de phare, Phare de Créac''h, Ouessant, France', 48.454851191507, -5.08825778961182, '1901 2000'),
(34743, 'Réflecteurs de phare, Phare de Créac''h, Ouessant, France', 48.4549365770936, -5.08838653564453, '1901 2000'),
(34744, ' Créac''h, Ouessant, France', 48.4547088818768, -5.08821487426758, '1801 2000'),
(34745, ' Toulalan, Ouessant, France', 48.4477636872284, -5.09061813354492, '1801 1900'),
(34746, ' Ouessant, France', 48.4556196566171, -5.09868621826172, '1801 1900'),
(34747, 'Gendarmerie, Ouessant, France', 48.4573273152184, -5.09593963623047, '1801 1900'),
(34748, 'Karaes, Ouessant, France', 48.4568719452077, -5.12134552001953, '1801 1900'),
(34749, ' Kerber, Ouessant, France', 48.4594902669904, -5.06641387939453, NULL),
(34750, ' Ouessant, France', 48.4574411570829, -5.09525299072266, NULL),
(34751, 'Église Saint-Paul-Aurélien,  Ouessant, France', 48.4569857880933, -5.09533882141113, '1401 1500'),
(34752, 'Église Saint-Paul-Aurélien,  Ouessant, France', 48.4569288666824, -5.09521007537842, '1801 1900'),
(34753, 'Église Saint-Paul-Aurélien,  Ouessant, France', 48.4570142487748, -5.09521007537842, '1801 1900'),
(34754, 'Cimetière, Ouessant, France', 48.4569857880933, -5.09576797485352, NULL),
(34755, 'Cimetière, Ouessant, France', 48.4574411570829, -5.09525299072266, '1901 2000'),
(34756, 'Ouessant, France', 48.4572134730987, -5.09611129760742, NULL),
(34757, ' Créac''h, Ouessant, France', 48.4545950338855, -5.08804321289062, NULL),
(34758, 'Porglaz, Ouessant, France', 48.4573273152184, -5.09611129760742, NULL),
(34759, ' Ouessant, France', 48.4535703904758, -5.09593963623047, NULL),
(34760, ' Pern, Ouessant, France', 48.4537980907983, -5.13078689575195, NULL),
(34761, 'Ouessant, France', 48.4578965219881, -5.09628295898438, NULL),
(34762, 'Chapelle Saint-Gildas, Ouessant, France', 48.4574980779195, -5.09615421295166, NULL),
(34763, 'Chapelle Saint-Gildas, Ouessant, France', 48.4575265383138, -5.09628295898438, '1601 1900'),
(34764, 'Feuntenn-Velen, Ouessant, France', 48.4573273152184, -5.09576797485352, NULL),
(34765, 'Porz-Chilin, Ouessant, France', 48.4574411570829, -5.09611129760742, '1901 2000'),
(34766, 'Stang-ar-Glan, Ouessant, France', 48.4592625921963, -5.0947380065918, '1901 2000'),
(34767, 'Pointe d''Ouessant, Ouessant, France', 48.4573273152184, -5.09628295898438, NULL),
(34768, ' Créac''h, Ouessant, France', 48.4588072395447, -5.13301849365234, '1901 1934'),
(34769, 'Pointe nord-ouest, Ouessant, France', 48.4849833824922, -5.07259368896484, '1912 1936');

-- --------------------------------------------------------

--
-- Structure de la table `mots_cles`
--

CREATE TABLE IF NOT EXISTS `mots_cles` (
  `id_mot_cle` int(11) DEFAULT '0',
  `id_element` bigint(20) NOT NULL DEFAULT '0',
  `mot_cle` text COLLATE utf8_bin
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Contenu de la table `mots_cles`
--

INSERT INTO `mots_cles` (`id_mot_cle`, `id_element`, `mot_cle`) VALUES
(3066, 34725, 'Mégalithe'),
(3066, 34725, 'Batiment'),
(2766, 34726, 'Château'),
(2766, 34726, 'Batiment'),
(2550, 34727, 'Phare'),
(2550, 34727, 'Batiment'),
(3024, 34728, 'Calvaire'),
(3024, 34728, 'Batiment'),
(2781, 34729, 'Maison'),
(3320, 34729, 'Demeure'),
(3320, 34729, 'Batiment'),
(2781, 34730, 'Maison'),
(2781, 34730, 'Batiment'),
(2781, 34731, 'Maison'),
(2781, 34731, 'Batiment'),
(2842, 34732, 'Cheminée'),
(2781, 34732, 'Batiment'),
(2885, 34733, 'Puits'),
(2885, 34733, 'Batiment'),
(2327, 34734, 'Crèche'),
(2327, 34734, 'Batiment'),
(3294, 34735, 'Costume traditionnel'),
(3294, 34735, 'Objet'),
(3483, 34736, 'Objet muséal'),
(3294, 34736, 'Costume traditionnel'),
(3294, 34736, 'Objet'),
(3087, 34737, 'Croix'),
(3190, 34737, 'Cérémonie'),
(3087, 34737, 'Objet'),
(2550, 34738, 'Phare'),
(2550, 34738, 'Batiment'),
(2675, 34739, 'Lampe'),
(2550, 34739, 'Phare'),
(2550, 34739, 'Objet'),
(2675, 34740, 'Lampe'),
(2550, 34740, 'Phare'),
(2550, 34740, 'Objet'),
(3264, 34741, 'Maquette'),
(3264, 34741, 'Objet'),
(2550, 34742, 'Phare'),
(2550, 34742, 'Objet'),
(3264, 34743, 'Maquette'),
(3264, 34743, 'Objet'),
(2550, 34744, 'Phare'),
(2550, 34744, 'Batiment'),
(2885, 34745, 'Puits'),
(2885, 34745, 'Batiment'),
(2552, 34746, 'Port'),
(2552, 34746, 'Batiment'),
(2704, 34747, 'Entrepôt'),
(2704, 34747, 'Batiment'),
(2596, 34748, 'Moulin à vent'),
(2596, 34748, 'Batiment'),
(2992, 34749, 'Chapelle'),
(2992, 34749, 'Batiment'),
(2995, 34750, 'Église'),
(2995, 34750, 'Batiment'),
(3124, 34751, 'Statue'),
(3124, 34751, 'Objet'),
(3051, 34752, 'Tronc'),
(3051, 34752, 'Objet'),
(3187, 34753, 'Tombe'),
(3187, 34753, 'Batiment'),
(3187, 34754, 'Tombe'),
(3187, 34754, 'Batiment'),
(3163, 34755, 'Monument aux morts'),
(3163, 34755, 'Batiment'),
(2228, 34756, 'Tour'),
(2228, 34756, 'Objet'),
(2550, 34757, 'Phare'),
(2550, 34757, 'Objet'),
(3006, 34758, 'Vestige de monument cultuel'),
(3006, 34758, 'Batiment'),
(3006, 34760, 'Vestige de monument cultuel'),
(3006, 34760, 'Batiment'),
(2992, 34761, 'Chapelle'),
(2992, 34761, 'Batiment'),
(3185, 34762, 'Stèle antique'),
(3024, 34762, 'Calvaire'),
(3024, 34762, 'Batiment'),
(2857, 34763, 'Fontaine'),
(2857, 34763, 'Batiment'),
(2541, 34764, 'Amer'),
(2541, 34764, 'Batiment'),
(3385, 34765, 'Abri naturel'),
(3385, 34765, 'Batiment'),
(2192, 34766, 'Caserne'),
(2192, 34766, 'Batiment'),
(2550, 34767, 'Phare'),
(2550, 34767, 'Batiment'),
(3500, 34768, 'signalisation maritime'),
(3500, 34768, 'Objet'),
(2550, 34769, 'Phare'),
(2550, 34769, 'Batiment');

-- --------------------------------------------------------

--
-- Structure de la table `parent_enfant`
--

CREATE TABLE IF NOT EXISTS `parent_enfant` (
  `id_element` bigint(20) NOT NULL DEFAULT '0',
  `id_element_parent` bigint(20) DEFAULT NULL,
  `id_element_enfant` bigint(20) DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Contenu de la table `parent_enfant`
--

INSERT INTO `parent_enfant` (`id_element`, `id_element_parent`, `id_element_enfant`) VALUES
(34725, NULL, NULL),
(34726, NULL, NULL),
(34727, NULL, NULL),
(34728, NULL, NULL),
(34729, NULL, NULL),
(34730, NULL, 34731),
(34730, NULL, 34732),
(34730, NULL, 34733),
(34730, NULL, 34734),
(34730, NULL, 34735),
(34731, 34730, NULL),
(34732, 34730, NULL),
(34733, 34730, NULL),
(34734, 34730, NULL),
(34735, 34730, NULL),
(34736, NULL, NULL),
(34737, NULL, NULL),
(34738, NULL, 34739),
(34738, NULL, 34740),
(34738, NULL, 34741),
(34738, NULL, 34742),
(34738, NULL, 34743),
(34739, 34738, NULL),
(34740, 34738, NULL),
(34741, 34738, NULL),
(34742, 34738, NULL),
(34743, 34738, NULL),
(34744, NULL, NULL),
(34745, NULL, NULL),
(34746, NULL, NULL),
(34747, NULL, NULL),
(34748, NULL, NULL),
(34749, NULL, NULL),
(34750, NULL, 34751),
(34750, NULL, 34752),
(34750, NULL, 34753),
(34751, 34750, NULL),
(34752, 34750, NULL),
(34753, 34750, NULL),
(34754, NULL, NULL),
(34755, NULL, NULL),
(34756, NULL, NULL),
(34757, NULL, NULL),
(34758, NULL, NULL),
(34759, NULL, NULL),
(34760, NULL, NULL),
(34761, NULL, 34762),
(34761, NULL, 34763),
(34762, 34761, NULL),
(34763, 34761, NULL),
(34764, NULL, NULL),
(34765, NULL, NULL),
(34766, NULL, NULL),
(34767, NULL, NULL),
(34768, NULL, NULL),
(34769, NULL, NULL);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
