# miniRT
> School21 project. Main aim - create render of 3D scene from *.rt file by using Raytracing method.

```make``` - compile program (miniRT) that doesn't works whith multi lights and textures.

```make bonus``` - compile program (miniRT_bonus). **Support multi lights and textrues.**

>To run compiled program you need to get it one parameter - name of scene file whith .rt extention. In /scenes/ you can find some of them. And you can create your own folowing the rules, which will be described below.

## *.rt file description (scene)

- Each type of element can be separated by one or more line break(s).
- Each type of information from an element can be separated by one or more space(s).
- Each type of element can be set in any order in the file.

## Available elements:

#### Ambient lightning:
|``` A 0.2 255,255,255```|
|:-------|
|**A** - type of element (Ambient lightning).|
|**0.2** - ratio in range [0.0 - 1.0].|
|**255,255,255** - R,G,B colors in range [0 - 255].|

#### Camera:

|``` C 30.0,0,2 0,0,1 70```|
|:-|
|**C** - type of element (Camera).|
|**30.0,0,2** - x,y,z coordinates of view point.|
|**0,0,1** - 3D orientation vector in range [0 - infinity].|
|**70** - FOV. Horizontal field of view in degrees [0 - 180].|

#### Light:

|```L -40.0,50.0,0.0 0.6 10,0,255```|
|:-|
|**L** - type of element.|
|**-40.0,50.0,0.0** - x,y,z coordinates of the light point.|
|**0.6** - brightness ratio in range [0.0 - 1.0].|
|**10,0,255** - R,G,B colors in range [0 - 255].|


#### Plane
|```pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225 ./dir/texture.xpm ./dir/map_normals.xpm```|
|:-|
|**pl** - type of element.|
|**0.0,0.0,-10.0** - x,y,z coordinates.|
|**0.0,0.0,1.0** - 3D orientation vector in range [0 - infinity].|
|**0,0,255** - R,G,B colors in range [0 - 255].|
|**./dir/texture.xpm** - path to texture file with .xpm extention.|
|**./dir/map_normals.xpm** - path to normal's file with .xpm extention.|

#### Sphere
|```sp 0.0,0.0,20.6 12.6 10,0,255 ./dir/texture.xpm ./dir/map_normals.xpm```|
|:-|
|**sp** - type of element (Camera).|
|**0.0,0.0,20.6** - x,y,z coordinates of the sphere center.|
|**12.6** - the sphere diameter.|
|**10,0,255** - R,G,B colors in range [0 - 255].|
|**./dir/texture.xpm** - path to texture file with .xpm extention.|
|**./dir/map_normals.xpm** - path to normal's file with .xpm extention.|

#### Cylinder
|```cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 ./dir/texture.xpm ./dir/map_normals.xpm```|
|:-|
|**cy** - type of element.|
|**0.0,0.0,20.6** - x,y,z coordinates of the down cap center.|
|**0.0,0.0,1.0** - 3D orientation vector in range [0 - infinity].|
|**14.2** - the cylinder diameter.|
|**21.46** - the cylinder height.|
|**10,0,255** - R,G,B colors in range [0 - 255].|
|**./dir/texture.xpm** - path to texture file with .xpm extention.|
|**./dir/map_normals.xpm** - path to normal's file with .xpm extention.|

#### Cone
|```co 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255 ./dir/texture.xpm ./dir/map_normals.xpm```|
|:-|
|**co** - type of element.|
|**0.0,0.0,20.6** - x,y,z coordinates of the down cap center.|
|**0.0,0.0,1.0** - 3D orientation vector in range [0 - infinity].|
|**14.2** - the cone diameter.|
|**21.46** - the cone height.|
|**10,0,255** - R,G,B colors in range [0 - 255].|
|**./dir/texture.xpm** - path to texture file with .xpm extention.|
|**./dir/map_normals.xpm** - path to normal's file with .xpm extention.|
----
> ./miniRT doesn't support textures, so if you want to execute that program you must not add textures to the scene file.

### Sample for miniRT program render some scene:
![in.rt](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_base.png)
----
>./miniRT_bonus - for this program you can add textures.

###  Sample for miniRT_bonus program render some scenes:
![View at cell](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_cell.png)
![View at all elements](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_all_view.png)

----

### And this is some samples how you can manipulate with textures (for miniRT_bonus):
If you specify path to the texture and normal map (for this variant we don't need to set the correct RGB color, becouse if there is at least one texture, the color isn't needed):

```cy 20.0,-10,00 1.0,1.0,0.0 10 120 258,0,255 ./textures/Bricks/Brickwall.xpm ./textures/Bricks/Brickwall_normal.xpm```
![cylinder with texture and normal map](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_cy_all_textured.png)

If you specify path to only normal map:

```cy20.0,-10,00 1.0,1.0,0.0 10 120 258,0,255 ./dir/map_normals.xpm```
![cylinder with only normal's map](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_cy_normals.png)

If you didn't specify path to the any texture (if you set the correct RGB color):

```cy 20.0,-10,00 1.0,1.0,0.0 10 120 255,0,255 ```
![cylinder with texture and normal map](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_cy_only_color.png)

If you didn't specify path to the any texture and don't set color (or wrong path for textures, or wrong color):

```cy 20.0,-10,00 1.0,1.0,0.0 10 120```
![cylinder without textures and color](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_cy_without_any_color.png)

----
### How that scene will look like if we remove normal map for plane from the scene file:
![Plane with texture but without normal map](https://github.com/mdenyse-en/screenshots/blob/master/miniRT/minirt_bonus_plane_without_normals.png)



