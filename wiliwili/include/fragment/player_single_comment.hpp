//
// Created by fang on 2023/1/6.
//

// register this fragment in main.cpp
//#include "fragment/player_single_comment.hpp"
//    brls::Application::registerXMLView("PlayerSingleComment", PlayerSingleComment::create);
// <brls:View xml=@res/xml/fragment/player_single_comment.xml

#pragma once

#include <borealis.hpp>
#include "bilibili/result/video_detail_result.h"

class VideoComment;
class RecyclingGrid;
class SVGImage;
class ButtonClose;

/// 评论详情页面
class PlayerSingleComment : public brls::Box {
public:
    PlayerSingleComment();

    void setCommentData(const bilibili::VideoCommentResult& result);

    void requestData();

    View* getDefaultFocus() override;

    void dismiss(std::function<void(void)> cb = nullptr) override;

    ~PlayerSingleComment();

    brls::Event<bool> likeStateEvent;
    brls::Event<size_t> likeNumEvent;
    brls::Event<size_t> replyNumEvent;
    brls::Event<> deleteEvent;

private:
    bilibili::VideoCommentResult root;
    bilibili::VideoCommentCursor cursor;
    BRLS_BIND(RecyclingGrid, recyclingGrid,
              "player/single/comment/recyclingGrid");
    BRLS_BIND(ButtonClose, closeBtn, "button/close");
};

/// 选择对单条评论的行为：点赞、回复、删除
class PlayerCommentAction : public brls::Box {
public:
    PlayerCommentAction();

    void setActionData(const bilibili::VideoCommentResult& data, float y);

    void showDelete();

    View* getDefaultFocus() override;

    void dismiss(std::function<void(void)> cb = nullptr) override;

    brls::Event<> likeClickEvent, replyClickEvent, deleteClickEvent;

private:
    BRLS_BIND(SVGImage, svgReply, "comment/action/svg/reply");
    BRLS_BIND(SVGImage, svgLike, "comment/action/svg/like");
    BRLS_BIND(SVGImage, svgDelete, "comment/action/svg/delete");
    BRLS_BIND(brls::Box, actionBox, "comment/action/box");
    BRLS_BIND(VideoComment, comment, "comment/action/comment");
    BRLS_BIND(ButtonClose, closeBtn, "button/close");
};