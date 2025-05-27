#ifndef PRO_TOOL_FILE_MERGE_H
#define PRO_TOOL_FILE_MERGE_H

#include "../pro_sample.h"

namespace pro::tools
{

class file_merge : public pro::dialog_sample<pro::global>
{
public:
    file_merge(pro::global& global);


public:
    ~file_merge();


protected:
    /*
     * tab
    */
    ext::ui::tab* tab_ = nullptr;
    /*
     * normal files
    */
    ext::ui::table* normal_files_ = nullptr;
    /*
     * statusbar
    */
    ext::ui::statusbar* statusbar_ = nullptr;
    /*
     * video audio form
    */
    ext::ui::form video_audio_form_;
    /*
     * state
    */
    std::atomic<uint8_t> state_ = ext::state::Running;
    /*
     * refcount
    */
    std::atomic_uint32_t refcount_ = 0;
    /*
     * process
    */
    ext::process process_;


protected:
    /*
     * init actions
    */
    void init_actions();


protected:
    /*
     * detect ffmpeg
    */
    void detect_ffmpeg();


protected:
    /*
     * merge normal files
    */
    void merge_normal_files(ext::cfile&& file,const std::vector<ext::fs::path>& paths);


protected:
    /*
     * merge done
    */
    void merge_done();
    /*
     * enable normal merge action
    */
    void enable_normal_merge_action();
    /*
     * enable normal actions
    */
    void enable_normal_actions(bool enable);


protected:
    /*
     * add
    */
    void normal_add(const std::vector<ext::text>& files);
    /*
     * add
    */
    void normal_add();
    /*
     * remove
    */
    void normal_remove();
    /*
     * clear
    */
    void normal_clear();
    /*
     * merge
    */
    void normal_merge();


protected:
    /*
     * video audio merge
    */
    void video_audio_merge();


public:
    /*
     * exec
    */
    void exec();

};

}


#endif
