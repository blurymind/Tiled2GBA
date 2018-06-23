#ifndef CODE_WRITER_H
#define CODE_WRITER_H

#include <string>
#include <vector>
#include <ostream>
#include <sstream>

using namespace std;

/**
 * Stores data in GBA format.
 */
class GBAMap {
public:
    /**
     * Construct a GBAMap to hold GBA Map data.
     * @param name The name of the map.
     */
    explicit GBAMap(const string &name);

    /**
     * Set the palette of the map.
     * @param bytes The color data.
     */
    void setPalette(vector<uint16_t> &bytes);

    /**
     * Set the Char block of the map.
     * @param bytes The Char block data.
     */
    void setTileSet(vector<uint16_t> &bytes);

    /**
     * Add a screen block to the map.
     * @param bytes The Screen block data.
     */
    void addTileLayer(vector<uint16_t> &bytes);

    /**
     * Convert the map data to C code.
     * @param headerFile The header file to store declarations in.
     * @param codeFile The code file to store definitions in.
     */
    void toCode(ostream &headerFile, ostream &codeFile);

private:
    void makeArrayDeclaration(ostream &headerStream, const string &name, vector<uint16_t> &bytes);
    void makeArrayDefinition(ostream &codeStream, const string &name, vector<uint16_t> &bytes);

private:
    const int LINE_LENGTH = 15;

    vector<uint16_t> d_palette, d_tileSet;
    vector<vector<uint16_t>> d_tileLayers;

    string d_name;
};

#endif