#include <concepts>

template <class Type>
concept deferable = requires {
    { std::declval<Type>()() } -> std::same_as<void>;
};

template <deferable Type>
class defer {
  Type fn;

 public:
  explicit defer(Type&& function) : fn{function} {}
  ~defer() { fn(); }

  defer(defer const&) = delete;
  defer(defer&&) = delete;
  defer& operator=(defer const&) = delete;
  defer& operator=(defer&&) = delete;
};