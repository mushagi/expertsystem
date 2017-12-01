/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expertsystem.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:42:24 by mmayibo           #+#    #+#             */
/*   Updated: 2017/12/02 01:02:04 by mmayibo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERTSYSTEM_HPP
#define EXPERTSYSTEM_HPP
#include <string>
#include <vector>
#include "../src/main/models/Rules.h"
#include "../src/main/models/Node.h"
#include "../src/main/models/Query.h"
int validate_query(vector<Node*> *nodes, vector<Rule*> *rules, Query query);
#endif
