
class BFEntityType {
    public:
    // char padding[288];
    int ncolors(); // 0x038
    int ncolors(int); // 0x038
    bool cIconZoom(); // 0x050
    bool cIconZoom(bool); // 0x050
    bool cExpansionID(); // 0x054 maybe int?
    bool cExpansionID(bool); // 0x054
    bool cMovable(); // 0x055
    bool cMovable(bool); // 0x055
    bool walkable(); // 0x056
    bool walkable(bool); // 0x056
    bool walkableByTall(); // 0x057
    bool walkableByTall(bool); // 0x057
    bool cRubbleable(); // 0x059
    bool cRubbleable(bool); // 0x059
    bool cUseNumbersInName(); // 0x05B
    bool cUseNumbersInName(bool); // 0x05B
    bool cUsesRealShadows(); // 0x05C
    bool cUsesRealShadows(bool); // 0x05C
    bool cHasShadowImages(); // 0x05D
    bool cHasShadowImages(bool); // 0x05D
    bool cForceShadowBlack(); // 0x05E
    bool cForceShadowBlack(bool); // 0x05E
    bool cDrawsLate(); // 0x060 <--- might need double checking, not available in canopies
    bool cDrawsLate(bool); // 0x060
    bool cHeight(); // 0x064
    bool cHeight(bool); // 0x064
    bool cDepth(); // 0x068
    bool cDepth(bool); // 0x068
    bool cHasUnderwaterSection(); // 0x06C
    bool cHasUnderwaterSection(bool); // 0x06C
    bool cIsTransient(); // 0x06D
    bool cIsTransient(bool); // 0x06D
    bool cUsesPlacementCube(); // 0x06E
    bool cUsesPlacementCube(bool); // 0x06E
    bool cShow(); //0x06F
    bool cShow(bool); //0x06F
    int cHitThreshold(); // 0x070
    int cHitThreshold(int); // 0x070
    bool cAvoidEdges(); // 0x074
    bool cAvoidEdges(bool); // 0x074
    std::string typeName(); // 0x098
    std::string typeName(std::string); // 0x098
    std::string codename(); // 0x0A4
    std::string codename(std::string); // 0x0A4
    int cFootprintX(); //0x0B4
    int cFootprintX(int); //0x0B4
    int cFootprintY(); //0x0B8
    int cFootprintY(int); //0x0B8
    int cFootprintZ(); //0x0BC
    int cFootprintZ(int); //0x0BC
    int cPlacementFootprintX(); //0x0C0
    int cPlacementFootprintX(int); //0x0C0
    int cPlacementFootprintY(); //0x0C4
    int cPlacementFootprintY(int); //0x0C4
    int cPlacementFootprintZ(); //0x0C8
    int cPlacementFootprintZ(int); //0x0C8
    bool availableAtStartup(); //0x0CC
    bool availableAtStartup(bool); //0x0CC

    BFEntityType(void* ptr) : thisptr(ptr) {};
    ~BFEntityType() {};

    protected:
    void* thisptr;
};