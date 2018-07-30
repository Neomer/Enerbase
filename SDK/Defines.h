#ifndef DEFINES_H
#define DEFINES_H

#define PROP(type, name)        private: type _##name; \
                                public: type get##name() const { return _##name; } \
                                void set##name(type value) { _##name = value; }

#define PROP_LINK(type, name)       private: type _##name; \
                                    public: type &get##name() { return _##name; } \
                                    void set##name(type value) { _##name = value; }

#define PROP_PTR(type, name)        private: type *_##name; \
                                    public: type *get##name() const { return _##name; } \
                                    void set##name(type *value) { _##name = value; }

#define SINGLETON(name)         private: name(); \
                                ~name() = default; \
                                name(name const &) = delete; \
                                name& operator= (name const&) = delete; \
                                name(name const &&) = delete; \
                                name& operator= (name const &&) = delete; \
                                public: static name &Instance();

#define STATIC(name)         private: name() = delete; \
                             ~name() = delete; \
                             name(name const &) = delete; \
                             name& operator= (name const&) = delete; \

#endif // DEFINES_H
