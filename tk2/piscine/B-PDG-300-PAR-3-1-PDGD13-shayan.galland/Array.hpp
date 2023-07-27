#include "iostream"

template <typename T, std::size_t Size>
class Array {
public:
  Array() {
    data = new T[Size];
  }

  ~Array() {
    delete[] data;
  }

  T& operator[](std::size_t index) {
    if (index >= Size) {
      throw std::out_of_range("Out of range");
    }
    return data[index];
  }

  const T& operator[](std::size_t index) const {
    if (index >= Size) {
      throw std::out_of_range("Out of range");
    }
    return data[index];
  }

  std::size_t size() const {
    return Size;
  }

  void forEach(const std::function<void(const T&)>& task) const {
    for (std::size_t i = 0; i < Size; i++) {
      task(data[i]);
    }
  }

  template <typename U>
  Array<U, Size> convert(const std::function<U(const T&)>& converter) const {
    Array<U, Size> result;
    for (std::size_t i = 0; i < Size; i++) {
      result[i] = converter(data[i]);
    }
    return result;
  }

  std::string toString() const {
    std::ostringstream oss;
    oss << "[";
    for (std::size_t i = 0; i < Size; i++) {
      oss << data[i];
      if (i < Size - 1) {
        oss << " , ";
      }
    }
    oss << "]";
    return oss.str();
  }

private:
  T* data;
};