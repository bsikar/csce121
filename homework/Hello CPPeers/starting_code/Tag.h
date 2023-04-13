#ifndef _TAG_H
#define _TAG_H

#include "Post.h"
#include <string>
#include <vector>

class Tag {
private:
  std::string tagName;
  std::vector<Post *> tagPosts;

public:
  Tag(std::string tagName);
  std::string getTagName();
  std::vector<Post *> &getTagPosts();
  void addTagPost(Post *post);
};

#endif
