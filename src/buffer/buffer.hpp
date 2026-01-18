/***
 * @file buffer.hpp
 * @brief Defination of the buffer class.
 * @author yuanyi
 *
 */
#include <string>

namespace buffer {

class buffer {
public:
  buffer();
  ~buffer();

  /**
   * @brief Add new text and update the current screen text
   * @param New text to add
   */
  void update_screen_text(std::string text);

private:
  std::string _history;     /**< Text of the history */
  std::string _screen_text; /**< Text of the current screen */
};

} // namespace buffer
