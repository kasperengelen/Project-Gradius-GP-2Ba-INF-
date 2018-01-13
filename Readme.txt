O================================================O
|                    README                      |
O================================================O

Resources
=========

Er is een bijgeleverde "resources" folder. Deze wordt gebruikt om
data op te slaan die door het spel gebruikt wordt zoals levels, 
textures, etc. In deze map zit een bestaan "settings.json", met daarin
de instellingen van het programma.

Settings.json
=============
 - "SCREEN_WIDTH": breedte van het scherm in pixels
 - "SCREEN_HEIGHT": hoogte van het scherm in pixels
 - "KEY_UP": keycode van toets om de speler omhoog te laten vliegen.
 - "KEY_DOWN": keycode van de toets om de speler omlaag te laten vliegen.
 - "KEY_LEFT": keycode van de toets om de speler naar links te laten vliegen.
 - "KEY_RIGHT": keycode van de toets om de speler naar rechts te laten vliegen.
 - "KEY_SHOOT": keycode van de toets om de speler een kogel af te doen schieten
 - "KEY_QUIT": keycode van de toets om het spel te beëindigen.
 - "FONT": filename van de font file gebruikt om tekst weer te geven.
 - "PLAYER_BULLET_SPRITE": filename van de sprite gebruikt om player bullets mee weer te geven.
 - "ENEMY_BULLET_SPRITE": filename van de sprite gebruikt om enemy bullets mee weer te geven.
 - "SHOW_HITBOX": toon de hitboxes van de entities.
 - "LEVEL_LIST": lijst van paden naar json files voor de levels.

Level formaat:
==============
 - "MaxXCoord": range van x-coordinaten die op het scherm worden weergegeven.
 - "MaxYCoord": range van y-coordinaten die op het scherm worden weergegeven.
    OPMERKING: de verhouding van MaxXCoord en MaxYCoord is het beste identiek
               aan de schermverhouding.
 - "PlayerData": data over de speler
    * "Symbol": symbool gebruikt om een speler te vermelden in de level matrix
    * "Sprite": filename van de sprite die gebruikt wordt om de speler voor te stellen
    * "Size": diameter van de speler in spelcoordinaten.
    * "BulletSpeed": snelheid van de kogels die de speler afschiet
    * "BulletSize": diameter van de kogels die de speler afschiet
    * "MaxShotsPerSecond": maximum aantal kogels dat de speler per seconde kan afvuren
    * "Lives": aantal levens van de speler
    * "Speed": snelheid van de speler

 - "FinishLine": data over de finish line. Dit is een soort "portaal" naar
        het volgende level.
    * "Symbol": symbool om de finish line voor te stellen in de level matrix.
    * "Sprite": filename van de sprite waarmee de finish line wordt voorgesteld.
    * "Size": diameter van de finish line.

 - "EnemyTypes": lijst van enemy specificaties.
    * "Symbol": symbool gebruikt om de enemy voor te stellen in de level matrix
    * "Sprite": filename van de sprite die gebruikt wordt om de enemy voor te stellen.
    * "Size": diameter van de enemy.
    * "Direction": direction vector die de richting aanduidt die de enemy uitgaat.
    * "BulletSpeed": snelheid van de kogels die de enemy afschiet.
    * "BulletSize": diamter van de kogels die de enemy afschiet.
    * "MaxShotsPerSecond": maximum aantal kogels dat de enemy per seconde mag afschieten
    * "AttackDamage": het aantal levels dat de speler verliest indien hij geraakt wordt door de enemy

 - "ObstacleTypes": lijst van specificaties van obstakels
    * "Symbol": symbool dat gebruikt wordt om het obstakel te vermelden in de level matrix.
    * "Size": diameter van het obstakel
    * "CollisionPenalty": het aantal levens dat de speler veliest indien hij botst tegen het obstakel.
    * "Sprite": filename van de sprite die gebruikt wordt om het obstakel voor te stellen

 - "LevelGrid": matrix die de layout van het level specifieerd.
    * rijen van symbolen: speler, enemies, obakels, etc.

Key codes:
==========
 - A:       0
 - B:       1
 - C:       2
 - D:       3
 - E:       4
 - F:       5
 - G:       6
 - H:       7
 - I:       8
 - J:       9
 - K:       10
 - L:       11
 - M:       12
 - N:       13
 - O:       14
 - P:       15
 - Q:       16
 - R:       17
 - S:       18
 - T:       19
 - U:       20
 - V:       21
 - W:       22
 - X:       23
 - Y:       24
 - Z:       25
 - ESCAPE:  26
 - SPACE:   27
 - ENTER:   28
 - TAB:     29
 - LCTRL:   30
 - RCTRL:   31
 - LSHIFT:  32
 - RSHIFT:  33
 - LALT:    34
 - RALT:    35
 - UP:      36
 - DOWN:    37
 - LEFT:    38
 - RIGHT:   39
 - Num0:    40
 - Num1:    41
 - Num2:    42
 - Num3:    43
 - Num4:    44
 - Num5:    45
 - Num6:    46
 - Num7:    47
 - Num8:    48
 - Num9:    49
 - Numpad0: 50
 - Numpad1: 51
 - Numpad2: 52
 - Numpad3: 53
 - Numpad4: 54
 - Numpad5: 55
 - Numpad6: 56
 - Numpad7: 57
 - Numpad8: 58
 - Numpad9: 59
 - F1:      60
 - F2:      61
 - F3:      62
 - F4:      63
 - F5:      64
 - F6:      65
 - F7:      66
 - F8:      67
 - F9:      68
 - F10:     69
 - F11:     70
 - F12:     71

