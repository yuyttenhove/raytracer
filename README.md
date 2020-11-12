# Raytracer

### TODO

- [x] fix lighting with cube
- [x] add way to save/load a meshcollection
- [x] make filepath different for different users
- [x] Importance sampling
- [x] Implement MSAA in camera
- [x] Redo recursive ray intensity calculation (only one bounce per ray per hit, shoot multiple rays (samples) per pixel)
- [x] Customizable FOV in Camera
- [ ] Use C++11 random library instead of `rand()`
- [ ] Remove hacky code DiffuseMaterial (l 25) (moved to `HalveUnitSphereVectorGenerator::generateCosineWeightedVectorAroundNormal`)
- [ ] Extend MeshGenerator (circle, square, sphere, cone, suzanne?, ...)
- [ ] Get OpenCV working
- [ ] Phong reflectance model
- [ ] pure absorbing material (ja dit kan al met een difuus materiaal met albedo 0, maar komaan, proper is t niet :p)
- [ ] use kd-tree or something similar for triangle stuff
- [ ] Parallelisation
- [ ] Add sun light
- [ ] add Reinhard tone mapping
- [ ] Russion roulette path termination
- [ ] next event estimation
- [ ] bidirection raytracing?
