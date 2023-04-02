#include "logic.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with
 * player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char **loadLevel(const string &fileName, int &maxRow, int &maxCol,
                 Player &player) {
  // if the input file is invalid return nullptr
  ifstream file(fileName);
  if (!file || file.eof()) {
    file.close();
    return nullptr;
  }

  // check validy of the file
  int tmp_max_row, tmp_max_col, tmp_player_row, tmp_player_col;
  file >> tmp_max_row >> tmp_max_col >> tmp_player_row >> tmp_player_col;

  // if the file is empty return nullptr
  if (file.eof()) {
    file.close();
    return nullptr;
  }

  // verify values are postive
  if (tmp_max_col < 0 || tmp_max_row < 0 || tmp_player_row < 0 ||
      tmp_player_col < 0) {
    file.close();
    return nullptr;
  }

  // verify that the maxRow * maxCol < INT32_MAX
  if (static_cast<unsigned long int>(tmp_max_row * tmp_max_col) >= INT32_MAX) {
    file.close();
    return nullptr;
  }

  // set maxRow and maxCol values
  maxRow = tmp_max_row;
  maxCol = tmp_max_col;
  player.row = tmp_player_row;
  player.col = tmp_player_col;

  // creates the map
  char **map = createMap(maxRow, maxCol);

  // add atributes to the map
  for (int i = 0; i < maxRow; ++i) {
    for (int j = 0; j < maxCol; ++j) {
      file >> map[i][j];
    }
  }
  map[player.row][player.col] = TILE_PLAYER;

  // check if file is empty
  string s;
  file >> s;
  if (!file.eof()) {
    file.close();
    return nullptr;
  }
  file.close();

  // return the map
  return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column
 * change. That is, updates the nextRow or nextCol according to the player's
 * movement direction.
 * @param   input       Character input by the user which translates to a
 * direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int &nextRow, int &nextCol) {
  // verify that input is only:
  // MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT
  // nextRow and nextCol are set to the right value
  // based on the input
  switch (input) {
  case MOVE_UP:
    nextRow -= 1;
    break;
  case MOVE_DOWN:
    nextRow += 1;
    break;
  case MOVE_LEFT:
    nextCol -= 1;
    break;
  case MOVE_RIGHT:
    nextCol += 1;
  }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char **createMap(int maxRow, int maxCol) {
  // if the input valis are invalid return nullptr
  if (maxRow <= 0 || maxCol <= 0 || maxRow > MAX_ROW_COL ||
      maxCol > MAX_ROW_COL) {
    return nullptr;
  }

  // alocated a 2d char array with maxRows and maxCols
  // initalize each element with TILE_OPEN
  char **map = new char *[maxRow];
  for (int i = 0; i < maxRow; i++) {
    map[i] = new char[maxCol];
  }

  for (int i = 0; i < maxRow; i++) {
    for (int j = 0; j < maxCol; j++) {
      map[i][j] = TILE_OPEN;
    }
  }

  // return a pointer to the new map
  return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char **&map, int &maxRow) {
  // delete the memory
  for (int i = 0; i < maxRow; i++) {
    delete[] map[i];
    map[i] = nullptr;
  }
  delete[] map;

  // set the map to nullptr
  map = nullptr;

  // setMax row to 0
  maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be
 * doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to
 * be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as
 * many columns and rows in size.
 * @update maxRow, maxCol
 */
char **resizeMap(char **map, int &maxRow, int &maxCol) {
  char **tmp_map = createMap(maxRow * 2, maxCol * 2);
  // if the map is null then return nullptr
  if (tmp_map == nullptr) {
    return nullptr;
  }

  int player_i;
  int player_j;
  for (int i = 0; i < maxRow; i++) {
    for (int j = 0; j < maxCol; j++) {
      tmp_map[i][j] = map[i][j];
      if (tmp_map[i][j] == TILE_PLAYER) {
        player_i = i;
        player_j = j;
        tmp_map[i][j] = TILE_OPEN;
      }
    }
  }

  int tmp_max_row = maxRow;
  int tmp_max_col = maxCol;

  deleteMap(map, maxRow);
  maxRow = tmp_max_row * 2;
  maxCol = tmp_max_col * 2;
  // top right
  for (int i = 0; i < maxRow / 2; i++) {
    for (int j = maxCol / 2; j < maxCol; j++) {
      int base_index = j - maxCol / 2;
      tmp_map[i][j] = tmp_map[i][base_index];
    }
  }

  // bottom left
  for (int i = maxRow / 2; i < maxRow; i++) {
    for (int j = 0; j < maxCol / 2; j++) {
      int base_index = i - maxRow / 2;
      tmp_map[i][j] = tmp_map[base_index][j];
    }
  }

  // bottom right
  for (int i = maxRow / 2; i < maxRow; i++) {
    for (int j = maxCol / 2; j < maxCol; j++) {
      int base_index_i = i - maxRow / 2;
      int base_index_j = j - maxCol / 2;
      tmp_map[i][j] = tmp_map[base_index_i][base_index_j];
    }
  }

  tmp_map[player_i][player_j] = TILE_PLAYER;

  return tmp_map;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the
 * move if so. Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure.
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the
 * appropriate status. You can use the STATUS constants defined in logic.h to
 * help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char **map, int maxRow, int maxCol, Player &player,
                 int nextRow, int nextCol) {
  // update the players col and row
  //
  // (check the nextRow and nextCol are in bounds)
  char status = STATUS_STAY;
  if (nextRow < 0 || nextCol < 0 || nextRow >= maxRow || nextCol >= maxCol) {
    return status;
  }

  char next_tile = map[nextRow][nextCol];

  // if the next pos is outside the bounds or on an impassible tile
  // then set the status to STATUS_STAY
  // and set the nextRow and nextCol to be the players current position
  if (next_tile == TILE_PILLAR || next_tile == TILE_MONSTER) {
    status = STATUS_STAY;
    goto bottom;
  }

  // if the next pos is on a tile then set the status and inc
  // the players treasure

  if (next_tile == TILE_TREASURE) {
    player.treasure += 1;
    status = STATUS_TREASURE;
    goto bottom;
  }

  // if the next pos is on an amulet then set the status
  if (next_tile == TILE_AMULET) {
    status = STATUS_AMULET;
    goto bottom;
  }

  // if the next pos is on a door to the next level then set the status
  if (next_tile == TILE_DOOR) {
    status = STATUS_LEAVE;
    goto bottom;
  }

  // if the next pos is on an exit to the dungeon:
  if (next_tile == TILE_EXIT) {
    //  and the adventurer
    //  has at least 1 piece of treausre then set the status
    if (player.treasure >= 1) {
      status = STATUS_ESCAPE;
      goto bottom;
    }
    //  otherwise if they had no treasure then treat the door as a pillar
    status = STATUS_STAY;
    goto bottom;
  }

  // if its open
  if (next_tile == TILE_OPEN) {
    status = STATUS_MOVE;
  }

bottom:
  if (status == STATUS_STAY) {
    return status;
  }

  map[nextRow][nextCol] = TILE_PLAYER;
  map[player.row][player.col] = TILE_OPEN;
  player.row = nextRow;
  player.col = nextCol;

  return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the
 * monster does not move. If we see a monster before an obstacle, the monster
 * moves one tile toward the player. We should update the map as the monster
 * moves. At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the
 * player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char **map, int maxRow, int maxCol, const Player &player) {
  bool player_dead = false;
  // check if there are monsters with a vertical or horizontal line of sight 1
  // tile or closer to the player

  // check up
  for (int i = player.row; i >= 0; i--) {
    char tile = map[i][player.col];

    if (tile == TILE_PILLAR) {
      break;
    }

    if (tile == TILE_MONSTER) {
      map[i][player.col] = TILE_OPEN;
      map[i + 1][player.col] = TILE_MONSTER;
    }
  }

  // check down
  for (int i = player.row; i < maxRow; i++) {
    char tile = map[i][player.col];

    if (tile == TILE_PILLAR) {
      break;
    }

    if (tile == TILE_MONSTER) {
      map[i][player.col] = TILE_OPEN;
      map[i - 1][player.col] = TILE_MONSTER;
    }
  }

  // check left
  for (int i = player.col; i >= 0; i--) {
    char tile = map[player.row][i];

    if (tile == TILE_PILLAR) {
      break;
    }

    if (tile == TILE_MONSTER) {
      map[player.row][i] = TILE_OPEN;
      map[player.row][i + 1] = TILE_MONSTER;
    }
  }

  // check right
  for (int i = player.col; i < maxCol; i++) {
    char tile = map[player.row][i];

    if (tile == TILE_PILLAR) {
      break;
    }

    if (tile == TILE_MONSTER) {
      map[player.row][i] = TILE_OPEN;
      map[player.row][i - 1] = TILE_MONSTER;
    }
  }

  // check if the player is on a monster tile
  if (map[player.row][player.col] == TILE_MONSTER) {
    player_dead = true;
  }

  return player_dead;
}
