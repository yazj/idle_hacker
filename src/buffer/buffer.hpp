/***
 * @file buffer.hpp
 * @brief Defination of the buffer class.
 * @author yuanyi
 *
 */
#include <deque>
#include <string>

namespace buffer {

class buffer {
public:
  buffer();
  ~buffer();

  /**
   * @brief Add a new line of text and update the current screen text
   * @param New text to add, must end with '\n'
   */
  void update_screen_text(const std::string &text);

private:
  std::deque<std::string> _history;     /**< Text of the history */
  std::deque<std::string> _screen_text; /**< Text of the current screen */
};

} // namespace buffer
