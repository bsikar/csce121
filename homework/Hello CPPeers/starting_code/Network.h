#ifndef _NETWORK_H
#define _NETWORK_H

#include "Post.h"
#include "Tag.h"
#include "User.h"
#include <string>
#include <vector>

class Network {
private:
  std::vector<User *> users;
  std::vector<Post *> posts;
  std::vector<Tag *> tags;

public:
  Network();
  ~Network();
  void loadFromFile(std::string fileName);
  void addUser(std::string userName);
  void addPost(unsigned int postId, std::string userName, std::string postText);
  std::vector<Post *> getPostsByUser(std::string userName);
  std::vector<Post *> getPostsWithTag(std::string tagName);
  std::vector<std::string> getMostPopularHashtag();
};

#endif
