/*
    board.cc
    David Gurevich
    CS 246
*/

#include "../include/board.h"

Board::Board()
{
    for (int i = 0; i < ROWS; i++)
    {
        positions.push_back(std::vector<Spot>());
        for (int j = 0; j < COLS; j++)
        {
            positions[i].push_back(Spot(i, j));
        }
    }

    white_move = true;
}

void Board::attach(Observer *o)
{
    observers.emplace_back(o);
}

void Board::detach(Observer *o)
{
    for (auto it = observers.begin(); it != observers.end();)
    {
        if (*it == o)
            it = observers.erase(it);
        else
            ++it;
    }
}

void Board::notify_observers()
{
    for (auto &ob : observers)
        ob->notify();
}

std::shared_ptr<Spot> Board::get_spot(int x, int y)
{
    return std::make_shared<Spot>(positions[x][y]);
}

bool Board::valid_path(Spot *from, Spot *to)
{
    Player *p;
    Piece *piece_from = from.get_piece();
    Piece *piece_to = to.get_piece();

    if (white_move)
    {
        p = white;
    }
    else
    {
        p = black;
    }

    Move *mv = Move(p, from, to, piece_from, piece_to);
    return piece_from->valid_move(*mv);
}

bool Board::is_attacking_path(Spot *end, Spot *attack_candidate_spot) // has a path attacking end
{
    Piece *e = end->get_piece();
    Piece *a = attack_candidate_spot->get_piece();
    bool same_team = e->is_white() == a->is_white();
    if (a == nullptr)
        return false;
    if (same_team)
        return true;

    // opposite team and invalid path
    return !valid_path(attack_candidate_spot, end);
}

bool Board::under_attack_vertical(Spot *spot)
{

    for (int y = spot->get_y(); y < ROWS; y++)
    {
        Spot *attack_candidate_spot = get_spot(spot->get_x(), y).get();
        if (is_attacking_path(spot, attack_candidate_spot))
        {
            return true;
            // if not attacking, the piece is either blocking, so there will be no direct attackers behind it or blank
        }
        else if (spot->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    for (int y = spot->get_y(); y >= 0; y--)
    {
        Spot *attack_candidate_spot = get_spot(spot->get_x(), y).get();
        if (is_attacking_path(spot, attack_candidate_spot))
        {
            return true;
        }
        else if (spot->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return false;
}

bool Board::under_attack_horizontal(Spot *spot)
{

    for (int x = spot->get_x(); x < COLS; x++)
    {
        Spot *attack_candidate_spot = get_spot(x, spot->get_y()).get();
        if (is_attacking_path(spot, attack_candidate_spot))
        {
            return true;
        }
        else if (spot->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    for (int x = spot->get_x(); x >= 0; x--)
    {
        Spot *attack_candidate_spot = get_spot(x, spot.get_y()).get();
        if (is_attacking_path(spot, attack_candidate_spot))
        {
            return true;
        }
        else if (spot->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return false;
}

bool Board::under_attack_diagonal(Spot *spot)
{
    // up right
    Spot *runner = spot;
    while (runner->in_bounds())
    {
        runner = get_spot(runner->get_x() + 1, runner->get_y() + 1).get();
        if (is_attacking_path(spot, runner))
        {
            return true;
        }
        else if (runner->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    // up left
    Spot *runner = spot;
    while (runner->in_bounds())
    {
        runner = get_spot(runner->get_x() - 1, runner->get_y() + 1).get();
        if (is_attacking_path(spot, runner))
        {
            return true;
        }
        else if (runner->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    // down right
    Spot *runner = spot;
    while (runner->in_bounds())
    {
        runner = get_spot(runner->get_x() + 1, runner->get_y() - 1).get();
        if (is_attacking_path(spot, runner))
        {
            return true;
        }
        else if (runner->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    // down left
    Spot *runner = spot;
    while (runner->in_bounds())
    {
        runner = get_spot(runner->get_x() - 1, runner->get_y() - 1).get();
        if (is_attacking_path(spot, runner))
        {
            return true;
        }
        else if (runner->is_blank())
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return false;
}

bool Board::under_attack(Spot *spot)
{
    return ((under_attack_vertical(spot) || under_attack_hoizontal(spot)) || under_attack_diagonal(spot)) || under_attack_knight(spot);
}

bool Board::check_valid_move(Move mv)
{

    if (!(mv.end_pos)->in_bounds())
        return false;
}